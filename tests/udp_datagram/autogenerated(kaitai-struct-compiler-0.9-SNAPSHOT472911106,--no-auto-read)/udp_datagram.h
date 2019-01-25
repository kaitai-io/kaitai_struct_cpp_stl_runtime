#ifndef UDP_DATAGRAM_H_
#define UDP_DATAGRAM_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"

#include <stdint.h>

#if KAITAI_STRUCT_VERSION < 7000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.7 or later is required"
#endif

/**
 * UDP is a simple stateless transport layer (AKA OSI layer 4)
 * protocol, one of the core Internet protocols. It provides source and
 * destination ports, basic checksumming, but provides not guarantees
 * of delivery, order of packets, or duplicate delivery.
 */

class udp_datagram_t : public kaitai::kstruct {

public:

    udp_datagram_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, udp_datagram_t* p__root = 0);
    void _read();
    ~udp_datagram_t();

private:
    uint16_t m_src_port;
    uint16_t m_dst_port;
    uint16_t m_length;
    uint16_t m_checksum;
    std::string m_body;
    udp_datagram_t* m__root;
    kaitai::kstruct* m__parent;

public:
    uint16_t src_port() const { return m_src_port; }
    uint16_t dst_port() const { return m_dst_port; }
    uint16_t length() const { return m_length; }
    uint16_t checksum() const { return m_checksum; }
    std::string body() const { return m_body; }
    udp_datagram_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // UDP_DATAGRAM_H_
