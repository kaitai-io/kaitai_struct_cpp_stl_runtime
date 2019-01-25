// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include <memory>
#include "custom_struct.h"



custom_struct_t::custom_struct_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, custom_struct_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = this;
    m_v_custom_type = 0;
    m_v_repeat1 = 0;
    m_v_repeat2 = 0;
}

void custom_struct_t::_read() {
    m_v_u1 = m__io->read_u1();
    m_v_s1 = m__io->read_s1();
    m_v_u2be = m__io->read_u2be();
    m_v_u2le = m__io->read_u2le();
    m_v_s2be = m__io->read_s2be();
    m_v_s2le = m__io->read_s2le();
    m_v_u4be = m__io->read_u4be();
    m_v_u4le = m__io->read_u4le();
    m_v_s4be = m__io->read_s4be();
    m_v_s4le = m__io->read_s4le();
    m_v_u8be = m__io->read_u8be();
    m_v_u8le = m__io->read_u8le();
    m_v_s8be = m__io->read_s8be();
    m_v_s8le = m__io->read_s8le();
    m_v_b1 = m__io->read_bits_int(1);
    m_v_b2 = m__io->read_bits_int(2);
    m_v_b3 = m__io->read_bits_int(3);
    m_v_b4 = m__io->read_bits_int(4);
    m_v_b5 = m__io->read_bits_int(5);
    m_v_b6 = m__io->read_bits_int(6);
    m_v_b7 = m__io->read_bits_int(7);
    m_v_b8 = m__io->read_bits_int(8);
    m_v_b9 = m__io->read_bits_int(9);
    m_v_b10 = m__io->read_bits_int(10);
    m_v_b24 = m__io->read_bits_int(24);
    m__io->align_to_byte();
    m_v_magic = m__io->read_fixed_contents(std::string("\x43\x55\x53\x54\x4F\x4D", 6));
    m_v_bytes = m__io->read_bytes(3);
    m_v_string = kaitai::kstream::bytes_to_str(m__io->read_bytes(3), std::string("ASCII"));
    m_v_enum = static_cast<custom_struct_t::enum_type1_t>(m__io->read_u1());
    m_v_custom_type = new custom_type1_t(m__io, this, m__root);
    m_v_custom_type->_read();
    m_v_repeat1_count = m__io->read_u1();
    int l_v_repeat1 = v_repeat1_count();
    m_v_repeat1 = new std::vector<custom_type1_t*>();
    m_v_repeat1->reserve(l_v_repeat1);
    for (int i = 0; i < l_v_repeat1; i++) {
        custom_type1_t* _t_v_repeat1 = new custom_type1_t(m__io, this, m__root);
        _t_v_repeat1->_read();
        m_v_repeat1->push_back(_t_v_repeat1);
    }
    m_v_repeat2_count = m__io->read_u1();
    int l_v_repeat2 = (v_repeat2_count() / 2);
    m_v_repeat2 = new std::vector<custom_type1_t*>();
    m_v_repeat2->reserve(l_v_repeat2);
    for (int i = 0; i < l_v_repeat2; i++) {
        custom_type1_t* _t_v_repeat2 = new custom_type1_t(m__io, this, m__root);
        _t_v_repeat2->_read();
        m_v_repeat2->push_back(_t_v_repeat2);
    }
}

void custom_struct_t::_write()
{
    m__io->write_u1(m_v_u1);
    m__io->write_s1(m_v_s1);
    m__io->write_u2be(m_v_u2be);
    m__io->write_u2le(m_v_u2le);
    m__io->write_s2be(m_v_s2be);
    m__io->write_s2le(m_v_s2le);
    m__io->write_u4be(m_v_u4be);
    m__io->write_u4le(m_v_u4le);
    m__io->write_s4be(m_v_s4be);
    m__io->write_s4le(m_v_s4le);
    m__io->write_u8be(m_v_u8be);
    m__io->write_u8le(m_v_u8le);
    m__io->write_s8be(m_v_s8be);
    m__io->write_s8le(m_v_s8le);
    m__io->write_bits_int(m_v_b1, 1);
    m__io->write_bits_int(m_v_b2, 2);
    m__io->write_bits_int(m_v_b3, 3);
    m__io->write_bits_int(m_v_b4, 4);
    m__io->write_bits_int(m_v_b5, 5);
    m__io->write_bits_int(m_v_b6, 6);
    m__io->write_bits_int(m_v_b7, 7);
    m__io->write_bits_int(m_v_b8, 8);
    m__io->write_bits_int(m_v_b9, 9);
    m__io->write_bits_int(m_v_b10, 10);
    m__io->write_bits_int(m_v_b24, 24);
    m__io->align_to_byte();
    m__io->write_fixed_contents(m_v_magic, std::string("\x43\x55\x53\x54\x4F\x4D", 6));
    m__io->write_bytes(m_v_bytes, 3);
    m__io->write_bytes(kaitai::kstream::bytes_to_str(m_v_string, std::string("ASCII")), 3);
    m__io->write_u1(m_v_enum);
    m_v_custom_type->_write();
    m__io->write_u1(m_v_repeat1_count);
    int l_v_repeat1 = v_repeat1_count();
    for (int i = 0; i < l_v_repeat1; i++) {
        custom_type1_t* _t_v_repeat1 = (*m_v_repeat1)[i];
        _t_v_repeat1->_write();
    }
    m__io->write_u1(m_v_repeat2_count);
    int l_v_repeat2 = (v_repeat2_count() / 2);
    for (int i = 0; i < l_v_repeat2; i++) {
        custom_type1_t* _t_v_repeat2 = (*m_v_repeat2)[i];
        _t_v_repeat2->_write();
    }
}

custom_struct_t::~custom_struct_t() {
    delete m_v_custom_type;
    for (std::vector<custom_type1_t*>::iterator it = m_v_repeat1->begin(); it != m_v_repeat1->end(); ++it) {
        delete *it;
    }
    delete m_v_repeat1;
    for (std::vector<custom_type1_t*>::iterator it = m_v_repeat2->begin(); it != m_v_repeat2->end(); ++it) {
        delete *it;
    }
    delete m_v_repeat2;
}

custom_struct_t::custom_type1_t::custom_type1_t(kaitai::kstream* p__io, custom_struct_t* p__parent, custom_struct_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
}

void custom_struct_t::custom_type1_t::_read() {
    m_magic = m__io->read_fixed_contents(std::string("\x43\x55\x53\x54\x4F\x4D\x5F\x54\x59\x50\x45\x31", 12));
    m_version = kaitai::kstream::bytes_to_str(m__io->read_bytes(1), std::string("ASCII"));
}

void custom_struct_t::custom_type1_t::_write()
{
    m__io->write_fixed_contents(m_magic, std::string("\x43\x55\x53\x54\x4F\x4D\x5F\x54\x59\x50\x45\x31", 12));
    m__io->write_bytes(kaitai::kstream::str_to_bytes(m_version, std::string("ASCII")), 1);
}

custom_struct_t::custom_type1_t::~custom_type1_t() {
}

custom_struct_t::custom_type2_t::custom_type2_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, custom_struct_t* p__root) : kaitai::kstruct(p__io) {
    m__parent = p__parent;
    m__root = p__root;
}

void custom_struct_t::custom_type2_t::_read() {
    m_magic = m__io->read_fixed_contents(std::string("\x43\x55\x53\x54\x4F\x4D\x5F\x54\x59\x50\x45\x32", 12));
    m_version = kaitai::kstream::bytes_to_str(m__io->read_bytes(2), std::string("ASCII"));
}

void custom_struct_t::custom_type2_t::_write()
{
    m__io->write_fixed_contents(m_magic, std::string("\x43\x55\x53\x54\x4F\x4D\x5F\x54\x59\x50\x45\x32", 12));
    m__io->write_bytes(kaitai::kstream::str_to_bytes(m_version, std::string("ASCII")), 2);
}

custom_struct_t::custom_type2_t::~custom_type2_t() {
}
