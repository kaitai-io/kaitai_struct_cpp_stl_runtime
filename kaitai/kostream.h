#ifndef KAITAI_KOSTREAM_H
#define KAITAI_KOSTREAM_H

#include <kaitai/kio.h>

#include <istream>
#include <sstream>
#include <stdint.h>
#include <sys/types.h>

namespace kaitai {

/**
 * Kaitai Output Stream class (kaitai::kostream) is an implementation of
 * <a href="https://github.com/kaitai-io/kaitai_struct/wiki/Kaitai-Struct-stream-API">Kaitai Struct stream API</a>
 * for C++/STL, for serialization. It's implemented as a wrapper over generic
 * STL std::ostream.
 *
 * It provides a wide variety of simple methods to write (serialize) binary
 * representations of primitive types, such as integer and floating
 * point numbers, byte arrays and strings, with unified cross-language and
 * cross-toolkit semantics.
 *
 * Typically, end users won't access Kaitai Stream classes manually, but would
 * describe a binary structure format using .ksy language and then would use
 * Kaitai Struct compiler to generate source code in desired target language.
 * That code, in turn, would use this class and API to do the actual parsing
 * job.
 */
class kostream : public virtual kio {
public:
    /**
     * Constructs new Kaitai Stream object, wrapping a given std::istream.
     * \param io istream object to use for this Kaitai Stream
     */
    kostream(std::ostream* io);

    /** @name Integer numbers */
    //@{

    // ------------------------------------------------------------------------
    // Signed
    // ------------------------------------------------------------------------

    void write_s1(int8_t t);

    // ........................................................................
    // Big-endian
    // ........................................................................

    void write_s2be(int16_t t);
    void write_s4be(int32_t t);
    void write_s8be(int64_t t);

    // ........................................................................
    // Little-endian
    // ........................................................................

    void write_s2le(int16_t t);
    void write_s4le(int32_t t);
    void write_s8le(int64_t t);

    // ------------------------------------------------------------------------
    // Unsigned
    // ------------------------------------------------------------------------

    void write_u1(uint8_t t);

    // ........................................................................
    // Big-endian
    // ........................................................................

    void write_u2be(uint16_t t);
    void write_u4be(uint32_t t);
    void write_u8be(uint64_t t);

    // ........................................................................
    // Little-endian
    // ........................................................................

    void write_u2le(uint16_t t);
    void write_u4le(uint32_t t);
    void write_u8le(uint64_t t);

    //@}

    /** @name Floating point numbers */
    //@{

    // ........................................................................
    // Big-endian
    // ........................................................................

    void write_f4be(float t);
    void write_f8be(double t);

    // ........................................................................
    // Little-endian
    // ........................................................................

    void write_f4le(float t);
    void write_f8le(double t);

    //@}

    /** @name Byte arrays */
    //@{

    void write_bytes(std::string bytes);

    //@}

private:
    std::ostream* m_io;
};

}

#endif
