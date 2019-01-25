// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include <memory>
#include "udp_datagram.h"



udp_datagram_t::udp_datagram_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, udp_datagram_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    _read();
}

void udp_datagram_t::_read() {
    m_src_port = m__io->read_u2be();
    m_dst_port = m__io->read_u2be();
    m_length = m__io->read_u2be();
    m_checksum = m__io->read_u2be();
    m_body = m__io->read_bytes_full();
}

udp_datagram_t::~udp_datagram_t() {
}
