#ifndef KAITAI_KIO_H
#define KAITAI_KIO_H

#include <iostream>
#include <stdint.h>

namespace kaitai {

class kio {
public:
    kio(std::ios* io);

    void close();
  
    /** @name Byte arrays */
    //@{

    static std::string bytes_strip_right(std::string src, char pad_byte);
    static std::string bytes_terminate(std::string src, char term, bool include);
    static std::string bytes_to_str(std::string src, std::string src_enc);

    //@}

    /** @name Byte array processing */
    //@{

    /**
     * Performs a XOR processing with given data, XORing every byte of input with a single
     * given value.
     * @param data data to process
     * @param key value to XOR with
     * @return processed data
     */
    static std::string process_xor_one(std::string data, uint8_t key);

    /**
     * Performs a XOR processing with given data, XORing every byte of input with a key
     * array, repeating key array many times, if necessary (i.e. if data array is longer
     * than key array).
     * @param data data to process
     * @param key array of bytes to XOR with
     * @return processed data
     */
    static std::string process_xor_many(std::string data, std::string key);

    /**
     * Performs a circular left rotation shift for a given buffer by a given amount of bits,
     * using groups of 1 bytes each time. Right circular rotation should be performed
     * using this procedure with corrected amount.
     * @param data source data to process
     * @param amount number of bits to shift by
     * @return copy of source array with requested shift applied
     */
    static std::string process_rotate_left(std::string data, int amount);

    //@}

    /**
     * Performs modulo operation between two integers: dividend `a`
     * and divisor `b`. Divisor `b` is expected to be positive. The
     * result is always 0 <= x <= b - 1.
     */
    static int mod(int a, int b);

    /**
     * Converts given integer `val` to a decimal string representation.
     * Should be used in place of std::to_string() (which is available only
     * since C++11) in older C++ implementations.
     */
    static std::string to_string(int val);

    /**
     * Reverses given string `val`, so that the first character becomes the
     * last and the last one becomes the first. This should be used to avoid
     * the need of local variables at the caller.
     */
    static std::string reverse(std::string val);

protected:
    /**
     * This constructor allows initialization to be deferred. This is needed
     * for when the stream is constructed in the derived class, since it will
     * not be able to construct it before constructing kaitai::kio.
     */
    kio();

    void init(std::ios* io);

    static uint64_t get_mask_ones(int n);

    void exceptions_enable() const;

private:
    std::ios* m_io;
};

}

#endif
