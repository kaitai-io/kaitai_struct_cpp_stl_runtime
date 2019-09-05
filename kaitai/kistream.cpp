#include <kaitai/kistream.h>
#include <kaitai/endian.h>

#include <iostream>
#include <vector>
#include <stdexcept>

kaitai::kstream::kstream(std::istream* io): kio(io) {
    m_io = io;
    init();
}

kaitai::kstream::kstream(std::string& data): m_io_str(data) {
    kio::init(&m_io_str);
    m_io = &m_io_str;
    init();
}

void kaitai::kstream::init() {
    align_to_byte();
}

// ========================================================================
// Stream positioning
// ========================================================================

bool kaitai::kstream::is_eof() const {
    if (m_bits_left > 0) {
        return false;
    }
    char t;
    m_io->exceptions(
        std::istream::badbit
    );
    m_io->get(t);
    if (m_io->eof()) {
        m_io->clear();
        exceptions_enable();
        return true;
    } else {
        m_io->unget();
        exceptions_enable();
        return false;
    }
}

void kaitai::kstream::seek(uint64_t pos) {
    m_io->seekg(pos);
}

uint64_t kaitai::kstream::pos() {
    return m_io->tellg();
}

uint64_t kaitai::kstream::size() {
    std::iostream::pos_type cur_pos = m_io->tellg();
    m_io->seekg(0, std::ios::end);
    std::iostream::pos_type len = m_io->tellg();
    m_io->seekg(cur_pos);
    return len;
}

// ========================================================================
// Integer numbers
// ========================================================================

// ------------------------------------------------------------------------
// Signed
// ------------------------------------------------------------------------

int8_t kaitai::kstream::read_s1() {
    char t;
    m_io->get(t);
    return t;
}

// ........................................................................
// Big-endian
// ........................................................................

int16_t kaitai::kstream::read_s2be() {
    int16_t t;
    m_io->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

int32_t kaitai::kstream::read_s4be() {
    int32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

int64_t kaitai::kstream::read_s8be() {
    int64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

// ........................................................................
// Little-endian
// ........................................................................

int16_t kaitai::kstream::read_s2le() {
    int16_t t;
    m_io->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

int32_t kaitai::kstream::read_s4le() {
    int32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

int64_t kaitai::kstream::read_s8le() {
    int64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

// ------------------------------------------------------------------------
// Unsigned
// ------------------------------------------------------------------------

uint8_t kaitai::kstream::read_u1() {
    char t;
    m_io->get(t);
    return t;
}

// ........................................................................
// Big-endian
// ........................................................................

uint16_t kaitai::kstream::read_u2be() {
    uint16_t t;
    m_io->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

uint32_t kaitai::kstream::read_u4be() {
    uint32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

uint64_t kaitai::kstream::read_u8be() {
    uint64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

// ........................................................................
// Little-endian
// ........................................................................

uint16_t kaitai::kstream::read_u2le() {
    uint16_t t;
    m_io->read(reinterpret_cast<char *>(&t), 2);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_16(t);
#endif
    return t;
}

uint32_t kaitai::kstream::read_u4le() {
    uint32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    return t;
}

uint64_t kaitai::kstream::read_u8le() {
    uint64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    return t;
}

// ========================================================================
// Floating point numbers
// ========================================================================

// ........................................................................
// Big-endian
// ........................................................................

float kaitai::kstream::read_f4be() {
    uint32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    return reinterpret_cast<float&>(t);
}

double kaitai::kstream::read_f8be() {
    uint64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    return reinterpret_cast<double&>(t);
}

// ........................................................................
// Little-endian
// ........................................................................

float kaitai::kstream::read_f4le() {
    uint32_t t;
    m_io->read(reinterpret_cast<char *>(&t), 4);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    return reinterpret_cast<float&>(t);
}

double kaitai::kstream::read_f8le() {
    uint64_t t;
    m_io->read(reinterpret_cast<char *>(&t), 8);
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    return reinterpret_cast<double&>(t);
}

// ========================================================================
// Unaligned bit values
// ========================================================================

void kaitai::kstream::align_to_byte() {
    m_bits_left = 0;
    m_bits = 0;
}

uint64_t kaitai::kstream::read_bits_int(int n) {
    int bits_needed = n - m_bits_left;
    if (bits_needed > 0) {
        // 1 bit  => 1 byte
        // 8 bits => 1 byte
        // 9 bits => 2 bytes
        int bytes_needed = ((bits_needed - 1) / 8) + 1;
        if (bytes_needed > 8)
            throw std::runtime_error("read_bits_int: more than 8 bytes requested");
        char buf[8];
        m_io->read(buf, bytes_needed);
        for (int i = 0; i < bytes_needed; i++) {
            uint8_t b = buf[i];
            m_bits <<= 8;
            m_bits |= b;
            m_bits_left += 8;
        }
    }

    // raw mask with required number of 1s, starting from lowest bit
    uint64_t mask = get_mask_ones(n);
    // shift mask to align with highest bits available in @bits
    int shift_bits = m_bits_left - n;
    mask <<= shift_bits;
    // derive reading result
    uint64_t res = (m_bits & mask) >> shift_bits;
    // clear top bits that we've just read => AND with 1s
    m_bits_left -= n;
    mask = get_mask_ones(m_bits_left);
    m_bits &= mask;

    return res;
}

// ========================================================================
// Byte arrays
// ========================================================================

std::string kaitai::kstream::read_bytes(std::streamsize len) {
    std::vector<char> result(len);

    // NOTE: streamsize type is signed, negative values are only *supposed* to not be used.
    // http://en.cppreference.com/w/cpp/io/streamsize
    if (len < 0) {
        throw std::runtime_error("read_bytes: requested a negative amount");
    }

    if (len > 0) {
        m_io->read(&result[0], len);
    }

    return std::string(result.begin(), result.end());
}

std::string kaitai::kstream::read_bytes_full() {
    std::iostream::pos_type p1 = m_io->tellg();
    m_io->seekg(0, std::ios::end);
    std::iostream::pos_type p2 = m_io->tellg();
    size_t len = p2 - p1;

    // Note: this requires a std::string to be backed with a
    // contiguous buffer. Officially, it's a only requirement since
    // C++11 (C++98 and C++03 didn't have this requirement), but all
    // major implementations had contiguous buffers anyway.
    std::string result(len, ' ');
    m_io->seekg(p1);
    m_io->read(&result[0], len);

    return result;
}

std::string kaitai::kstream::read_bytes_term(char term, bool include, bool consume, bool eos_error) {
    std::string result;
    std::getline(*m_io, result, term);
    if (m_io->eof()) {
        // encountered EOF
        if (eos_error) {
            throw std::runtime_error("read_bytes_term: encountered EOF");
        }
    } else {
        // encountered terminator
        if (include)
            result.push_back(term);
        if (!consume)
            m_io->unget();
    }
    return result;
}

std::string kaitai::kstream::ensure_fixed_contents(std::string expected) {
    std::string actual = read_bytes(expected.length());

    if (actual != expected) {
        // NOTE: I think printing it outright is not best idea, it could contain non-ascii charactes like backspace and beeps and whatnot. It would be better to print hexlified version, and also to redirect it to stderr.
        throw std::runtime_error("ensure_fixed_contents: actual data does not match expected data");
    }

    return actual;
}

// ========================================================================
// Byte array processing
// ========================================================================

#ifdef KS_ZLIB
#include <zlib.h>

std::string kaitai::kstream::process_zlib(std::string data) {
    int ret;

    unsigned char *src_ptr = reinterpret_cast<unsigned char*>(&data[0]);
    std::stringstream dst_strm;

    z_stream strm;
    strm.zalloc = Z_NULL;
    strm.zfree = Z_NULL;
    strm.opaque = Z_NULL;

    ret = inflateInit(&strm);
    if (ret != Z_OK)
        throw std::runtime_error("process_zlib: inflateInit error");

    strm.next_in = src_ptr;
    strm.avail_in = data.length();

    unsigned char outbuffer[ZLIB_BUF_SIZE];
    std::string outstring;

    // get the decompressed bytes blockwise using repeated calls to inflate
    do {
        strm.next_out = reinterpret_cast<Bytef*>(outbuffer);
        strm.avail_out = sizeof(outbuffer);

        ret = inflate(&strm, 0);

        if (outstring.size() < strm.total_out)
            outstring.append(reinterpret_cast<char*>(outbuffer), strm.total_out - outstring.size());
    } while (ret == Z_OK);

    if (ret != Z_STREAM_END) {          // an error occurred that was not EOF
        std::ostringstream exc_msg;
        exc_msg << "process_zlib: error #" << ret << "): " << strm.msg;
        throw std::runtime_error(exc_msg.str());
    }

    if (inflateEnd(&strm) != Z_OK)
        throw std::runtime_error("process_zlib: inflateEnd error");

    return outstring;
}
#endif
