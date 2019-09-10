#include <kaitai/kostream.h>
#include <kaitai/endian.h>

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace ::kaitai;

kostream::kostream(std::ostream* io): kio(io) {
    m_io = io;
}

// ========================================================================
// Integer numbers
// ========================================================================

// ------------------------------------------------------------------------
// Signed
// ------------------------------------------------------------------------

void kostream::write_s1(int8_t t) {
    m_io->put(t);
}

// ........................................................................
// Big-endian
// ........................................................................

void kostream::write_s2be(int16_t t) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_16(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 2);
}

void kostream::write_s4be(int32_t t) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 4);
}

void kostream::write_s8be(int64_t t) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 8);
}

// ........................................................................
// Little-endian
// ........................................................................

void kostream::write_s2le(int16_t t) {
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_16(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 2);
}

void kostream::write_s4le(int32_t t) {
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 4);
}

void kostream::write_s8le(int64_t t) {
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 8);
}

// ------------------------------------------------------------------------
// Unsigned
// ------------------------------------------------------------------------

void kostream::write_u1(uint8_t t) {
    m_io->put(t);
}

// ........................................................................
// Big-endian
// ........................................................................

void kostream::write_u2be(uint16_t t) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_16(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 8);
}

void kostream::write_u4be(uint32_t t) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 8);
}

void kostream::write_u8be(uint64_t t) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 8);
}

// ........................................................................
// Little-endian
// ........................................................................

void kostream::write_u2le(uint16_t t) {
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_16(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 2);
}

void kostream::write_u4le(uint32_t t) {
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 4);
}

void kostream::write_u8le(uint64_t t) {
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 8);
}

// ========================================================================
// Floating point numbers
// ========================================================================

// ........................................................................
// Big-endian
// ........................................................................

void kostream::write_f4be(float t) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_32(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 4);
}

void kostream::write_f8be(double t) {
#if __BYTE_ORDER == __LITTLE_ENDIAN
    t = bswap_64(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 8);
}

// ........................................................................
// Little-endian
// ........................................................................

void kostream::write_f4le(float t) {
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_32(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 4);
}

void kostream::write_f8le(double t) {
#if __BYTE_ORDER == __BIG_ENDIAN
    t = bswap_64(t);
#endif
    m_io->write(reinterpret_cast<char *>(&t), 8);
}

// ========================================================================
// Byte arrays
// ========================================================================

void kostream::write_bytes(std::string bytes) {
    m_io->write(bytes.data(), bytes.length());
}
