#ifndef CUSTOM_STRUCT_H_
#define CUSTOM_STRUCT_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"

#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 7000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.7 or later is required"
#endif

/**
 * This is a custom struct.
 * It contains u1, s1, u2be, u2le, s2be, s2le, u4be, u4le, s4be, s4le,
 * u8be, u8le, s8be, s8le, b1, b2, b3, b4, b5, b6, b7, b8, b9, b10, b24,
 * magic, bytes, string, enum, (custom_type), (repeat), (expression).
 */

class custom_struct_t : public kaitai::kstruct {

public:
    class custom_type1_t;
    class custom_type2_t;

    enum enum_type1_t {
        ENUM_TYPE1_ENUM_TYPE1_ITEM1 = 1,
        ENUM_TYPE1_ENUM_TYPE1_ITEM2 = 2,
        ENUM_TYPE1_ENUM_TYPE1_ITEM3 = 3
    };

    enum enum_type2_t {
        ENUM_TYPE2_ENUM_TYPE2_ITEM1 = 1,
        ENUM_TYPE2_ENUM_TYPE2_ITEM2 = 2,
        ENUM_TYPE2_ENUM_TYPE2_ITEM3 = 4
    };

    custom_struct_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, custom_struct_t* p__root = 0);
    void _read();
    ~custom_struct_t();

    class custom_type1_t : public kaitai::kstruct {

    public:

        custom_type1_t(kaitai::kstream* p__io, custom_struct_t* p__parent = 0, custom_struct_t* p__root = 0);
        void _read();
        ~custom_type1_t();

    private:
        std::string m_magic;
        std::string m_version;
        custom_struct_t* m__root;
        custom_struct_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        std::string version() const { return m_version; }
        custom_struct_t* _root() const { return m__root; }
        custom_struct_t* _parent() const { return m__parent; }
    };

    class custom_type2_t : public kaitai::kstruct {

    public:

        custom_type2_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, custom_struct_t* p__root = 0);
        void _read();
        ~custom_type2_t();

    private:
        std::string m_magic;
        std::string m_version;
        custom_struct_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        std::string magic() const { return m_magic; }
        std::string version() const { return m_version; }
        custom_struct_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

private:
    uint8_t m_v_u1;
    int8_t m_v_s1;
    uint16_t m_v_u2be;
    uint16_t m_v_u2le;
    int16_t m_v_s2be;
    int16_t m_v_s2le;
    uint32_t m_v_u4be;
    uint32_t m_v_u4le;
    int32_t m_v_s4be;
    int32_t m_v_s4le;
    uint64_t m_v_u8be;
    uint64_t m_v_u8le;
    int64_t m_v_s8be;
    int64_t m_v_s8le;
    bool m_v_b1;
    uint64_t m_v_b2;
    uint64_t m_v_b3;
    uint64_t m_v_b4;
    uint64_t m_v_b5;
    uint64_t m_v_b6;
    uint64_t m_v_b7;
    uint64_t m_v_b8;
    uint64_t m_v_b9;
    uint64_t m_v_b10;
    uint64_t m_v_b24;
    std::string m_v_magic;
    std::string m_v_bytes;
    std::string m_v_string;
    enum_type1_t m_v_enum;
    custom_type1_t* m_v_custom_type;
    uint8_t m_v_repeat1_count;
    std::vector<custom_type1_t*>* m_v_repeat1;
    uint8_t m_v_repeat2_count;
    std::vector<custom_type1_t*>* m_v_repeat2;
    custom_struct_t* m__root;
    kaitai::kstruct* m__parent;

public:
    uint8_t v_u1() const { return m_v_u1; }
    int8_t v_s1() const { return m_v_s1; }
    uint16_t v_u2be() const { return m_v_u2be; }
    uint16_t v_u2le() const { return m_v_u2le; }
    int16_t v_s2be() const { return m_v_s2be; }
    int16_t v_s2le() const { return m_v_s2le; }
    uint32_t v_u4be() const { return m_v_u4be; }
    uint32_t v_u4le() const { return m_v_u4le; }
    int32_t v_s4be() const { return m_v_s4be; }
    int32_t v_s4le() const { return m_v_s4le; }
    uint64_t v_u8be() const { return m_v_u8be; }
    uint64_t v_u8le() const { return m_v_u8le; }
    int64_t v_s8be() const { return m_v_s8be; }
    int64_t v_s8le() const { return m_v_s8le; }
    bool v_b1() const { return m_v_b1; }
    uint64_t v_b2() const { return m_v_b2; }
    uint64_t v_b3() const { return m_v_b3; }
    uint64_t v_b4() const { return m_v_b4; }
    uint64_t v_b5() const { return m_v_b5; }
    uint64_t v_b6() const { return m_v_b6; }
    uint64_t v_b7() const { return m_v_b7; }
    uint64_t v_b8() const { return m_v_b8; }
    uint64_t v_b9() const { return m_v_b9; }
    uint64_t v_b10() const { return m_v_b10; }
    uint64_t v_b24() const { return m_v_b24; }
    std::string v_magic() const { return m_v_magic; }
    std::string v_bytes() const { return m_v_bytes; }
    std::string v_string() const { return m_v_string; }
    enum_type1_t v_enum() const { return m_v_enum; }
    custom_type1_t* v_custom_type() const { return m_v_custom_type; }
    uint8_t v_repeat1_count() const { return m_v_repeat1_count; }
    std::vector<custom_type1_t*>* v_repeat1() const { return m_v_repeat1; }
    uint8_t v_repeat2_count() const { return m_v_repeat2_count; }
    std::vector<custom_type1_t*>* v_repeat2() const { return m_v_repeat2; }
    custom_struct_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
};

#endif  // CUSTOM_STRUCT_H_
