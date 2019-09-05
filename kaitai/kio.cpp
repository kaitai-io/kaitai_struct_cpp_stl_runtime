#include <kaitai/kio.h>

#include <iostream>
#include <stdexcept>

kaitai::kio::kio() {
}

kaitai::kio::kio(std::ios* io) {
    init(io);
}

void kaitai::kio::init(std::ios* io) {
    m_io = io;
    exceptions_enable();
}

void kaitai::kio::close() {
    //  m_io->close();
}

void kaitai::kio::exceptions_enable() const {
    m_io->exceptions(
        std::ios::eofbit |
        std::ios::failbit |
        std::ios::badbit
    );
}

// ========================================================================
// Byte arrays
// ========================================================================

std::string kaitai::kio::bytes_strip_right(std::string src, char pad_byte) {
    std::size_t new_len = src.length();

    while (new_len > 0 && src[new_len - 1] == pad_byte)
        new_len--;

    return src.substr(0, new_len);
}

std::string kaitai::kio::bytes_terminate(std::string src, char term, bool include) {
    std::size_t new_len = 0;
    std::size_t max_len = src.length();

    while (new_len < max_len && src[new_len] != term)
        new_len++;

    if (include && new_len < max_len)
        new_len++;

    return src.substr(0, new_len);
}

// ========================================================================
// Byte array processing
// ========================================================================

std::string kaitai::kio::process_xor_one(std::string data, uint8_t key) {
    size_t len = data.length();
    std::string result(len, ' ');

    for (size_t i = 0; i < len; i++)
        result[i] = data[i] ^ key;

    return result;
}

std::string kaitai::kio::process_xor_many(std::string data, std::string key) {
    size_t len = data.length();
    size_t kl = key.length();
    std::string result(len, ' ');

    size_t ki = 0;
    for (size_t i = 0; i < len; i++) {
        result[i] = data[i] ^ key[ki];
        ki++;
        if (ki >= kl)
            ki = 0;
    }

    return result;
}

std::string kaitai::kio::process_rotate_left(std::string data, int amount) {
    size_t len = data.length();
    std::string result(len, ' ');

    for (size_t i = 0; i < len; i++) {
        uint8_t bits = data[i];
        result[i] = (bits << amount) | (bits >> (8 - amount));
    }

    return result;
}

// ========================================================================
// Misc utility methods
// ========================================================================

int kaitai::kio::mod(int a, int b) {
    if (b <= 0)
        throw std::invalid_argument("mod: divisor b <= 0");
    int r = a % b;
    if (r < 0)
        r += b;
    return r;
}

#include <stdio.h>
std::string kaitai::kio::to_string(int val) {
    // if int is 32 bits, "-2147483648" is the longest string representation
    //   => 11 chars + zero => 12 chars
    // if int is 64 bits, "-9223372036854775808" is the longest
    //   => 20 chars + zero => 21 chars
    char buf[25];
    int got_len = snprintf(buf, sizeof(buf), "%d", val);

    // should never happen, but check nonetheless
    if (got_len > sizeof(buf))
        throw std::invalid_argument("to_string: integer is longer than string buffer");

    return std::string(buf);
}

#include <algorithm>
std::string kaitai::kio::reverse(std::string val) {
    std::reverse(val.begin(), val.end());

    return val;
}

// ========================================================================
// Other internal methods
// ========================================================================

uint64_t kaitai::kio::get_mask_ones(int n) {
    if (n == 64) {
        return 0xFFFFFFFFFFFFFFFF;
    } else {
        return ((uint64_t) 1 << n) - 1;
    }
}

#ifndef KS_STR_DEFAULT_ENCODING
#define KS_STR_DEFAULT_ENCODING "UTF-8"
#endif

#ifdef KS_STR_ENCODING_ICONV

#include <iconv.h>
#include <cerrno>
#include <stdexcept>

std::string kaitai::kio::bytes_to_str(std::string src, std::string src_enc) {
    iconv_t cd = iconv_open(KS_STR_DEFAULT_ENCODING, src_enc.c_str());

    if (cd == (iconv_t) -1) {
        if (errno == EINVAL) {
            throw std::runtime_error("bytes_to_str: invalid encoding pair conversion requested");
        } else {
            throw std::runtime_error("bytes_to_str: error opening iconv");
        }
    }

    size_t src_len = src.length();
    size_t src_left = src_len;

    // Start with a buffer length of double the source length.
    size_t dst_len = src_len * 2;
    std::string dst(dst_len, ' ');
    size_t dst_left = dst_len;

    char *src_ptr = &src[0];
    char *dst_ptr = &dst[0];

    while (true) {
        size_t res = iconv(cd, &src_ptr, &src_left, &dst_ptr, &dst_left);

        if (res == (size_t) -1) {
            if (errno == E2BIG) {
                // dst buffer is not enough to accomodate whole string
                // enlarge the buffer and try again
                size_t dst_used = dst_len - dst_left;
                dst_left += dst_len;
                dst_len += dst_len;
                dst.resize(dst_len);

                // dst.resize might have allocated destination buffer in another area
                // of memory, thus our previous pointer "dst" will be invalid; re-point
                // it using "dst_used".
                dst_ptr = &dst[dst_used];
            } else {
                throw std::runtime_error("bytes_to_str: iconv error");
            }
        } else {
            // conversion successful
            dst.resize(dst_len - dst_left);
            break;
        }
    }

    if (iconv_close(cd) != 0) {
        throw std::runtime_error("bytes_to_str: iconv close error");
    }

    return dst;
}
#elif defined(KS_STR_ENCODING_NONE)
std::string kaitai::kio::bytes_to_str(std::string src, std::string src_enc) {
    return src;
}
#else
#error Need to decide how to handle strings: please define one of: KS_STR_ENCODING_ICONV, KS_STR_ENCODING_NONE
#endif
