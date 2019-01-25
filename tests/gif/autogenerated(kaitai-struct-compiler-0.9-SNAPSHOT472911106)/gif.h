#ifndef GIF_H_
#define GIF_H_

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"

#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 7000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.7 or later is required"
#endif

/**
 * GIF (Graphics Interchange Format) is an image file format, developed
 * in 1987. It became popular in 1990s as one of the main image formats
 * used in World Wide Web.
 * 
 * GIF format allows encoding of palette-based images up to 256 colors
 * (each of the colors can be chosen from a 24-bit RGB
 * colorspace). Image data stream uses LZW (Lempel¨CZiv¨CWelch) lossless
 * compression.
 * 
 * Over the years, several version of the format were published and
 * several extensions to it were made, namely, a popular Netscape
 * extension that allows to store several images in one file, switching
 * between them, which produces crude form of animation.
 * 
 * Structurally, format consists of several mandatory headers and then
 * a stream of blocks follows. Blocks can carry additional
 * metainformation or image data.
 */

class gif_t : public kaitai::kstruct {

public:
    class image_data_t;
    class color_table_entry_t;
    class logical_screen_descriptor_struct_t;
    class local_image_descriptor_t;
    class block_t;
    class color_table_t;
    class header_t;
    class ext_graphic_control_t;
    class subblock_t;
    class ext_application_t;
    class subblocks_t;
    class extension_t;

    enum block_type_t {
        BLOCK_TYPE_EXTENSION = 33,
        BLOCK_TYPE_LOCAL_IMAGE_DESCRIPTOR = 44,
        BLOCK_TYPE_END_OF_FILE = 59
    };

    enum extension_label_t {
        EXTENSION_LABEL_GRAPHIC_CONTROL = 249,
        EXTENSION_LABEL_COMMENT = 254,
        EXTENSION_LABEL_APPLICATION = 255
    };

    gif_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gif_t* p__root = 0);

private:
    void _read();

public:
    ~gif_t();

    /**
     * \sa - section 22
     */

    class image_data_t : public kaitai::kstruct {

    public:

        image_data_t(kaitai::kstream* p__io, gif_t::local_image_descriptor_t* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~image_data_t();

    private:
        uint8_t m_lzw_min_code_size;
        subblocks_t* m_subblocks;
        gif_t* m__root;
        gif_t::local_image_descriptor_t* m__parent;

    public:
        uint8_t lzw_min_code_size() const { return m_lzw_min_code_size; }
        subblocks_t* subblocks() const { return m_subblocks; }
        gif_t* _root() const { return m__root; }
        gif_t::local_image_descriptor_t* _parent() const { return m__parent; }
    };

    class color_table_entry_t : public kaitai::kstruct {

    public:

        color_table_entry_t(kaitai::kstream* p__io, gif_t::color_table_t* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~color_table_entry_t();

    private:
        uint8_t m_red;
        uint8_t m_green;
        uint8_t m_blue;
        gif_t* m__root;
        gif_t::color_table_t* m__parent;

    public:
        uint8_t red() const { return m_red; }
        uint8_t green() const { return m_green; }
        uint8_t blue() const { return m_blue; }
        gif_t* _root() const { return m__root; }
        gif_t::color_table_t* _parent() const { return m__parent; }
    };

    /**
     * \sa - section 18
     */

    class logical_screen_descriptor_struct_t : public kaitai::kstruct {

    public:

        logical_screen_descriptor_struct_t(kaitai::kstream* p__io, gif_t* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~logical_screen_descriptor_struct_t();

    private:
        bool f_has_color_table;
        bool m_has_color_table;

    public:
        bool has_color_table();

    private:
        bool f_color_table_size;
        int32_t m_color_table_size;

    public:
        int32_t color_table_size();

    private:
        uint16_t m_screen_width;
        uint16_t m_screen_height;
        uint8_t m_flags;
        uint8_t m_bg_color_index;
        uint8_t m_pixel_aspect_ratio;
        gif_t* m__root;
        gif_t* m__parent;

    public:
        uint16_t screen_width() const { return m_screen_width; }
        uint16_t screen_height() const { return m_screen_height; }
        uint8_t flags() const { return m_flags; }
        uint8_t bg_color_index() const { return m_bg_color_index; }
        uint8_t pixel_aspect_ratio() const { return m_pixel_aspect_ratio; }
        gif_t* _root() const { return m__root; }
        gif_t* _parent() const { return m__parent; }
    };

    class local_image_descriptor_t : public kaitai::kstruct {

    public:

        local_image_descriptor_t(kaitai::kstream* p__io, gif_t::block_t* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~local_image_descriptor_t();

    private:
        bool f_has_color_table;
        bool m_has_color_table;

    public:
        bool has_color_table();

    private:
        bool f_has_interlace;
        bool m_has_interlace;

    public:
        bool has_interlace();

    private:
        bool f_has_sorted_color_table;
        bool m_has_sorted_color_table;

    public:
        bool has_sorted_color_table();

    private:
        bool f_color_table_size;
        int32_t m_color_table_size;

    public:
        int32_t color_table_size();

    private:
        uint16_t m_left;
        uint16_t m_top;
        uint16_t m_width;
        uint16_t m_height;
        uint8_t m_flags;
        color_table_t* m_local_color_table;
        bool n_local_color_table;

    public:
        bool _is_null_local_color_table() { local_color_table(); return n_local_color_table; };

    private:
        image_data_t* m_image_data;
        gif_t* m__root;
        gif_t::block_t* m__parent;
        std::string m__raw_local_color_table;
        bool n__raw_local_color_table;

    public:
        bool _is_null__raw_local_color_table() { _raw_local_color_table(); return n__raw_local_color_table; };

    private:
        kaitai::kstream* m__io__raw_local_color_table;

    public:
        uint16_t left() const { return m_left; }
        uint16_t top() const { return m_top; }
        uint16_t width() const { return m_width; }
        uint16_t height() const { return m_height; }
        uint8_t flags() const { return m_flags; }
        color_table_t* local_color_table() const { return m_local_color_table; }
        image_data_t* image_data() const { return m_image_data; }
        gif_t* _root() const { return m__root; }
        gif_t::block_t* _parent() const { return m__parent; }
        std::string _raw_local_color_table() const { return m__raw_local_color_table; }
        kaitai::kstream* _io__raw_local_color_table() const { return m__io__raw_local_color_table; }
    };

    class block_t : public kaitai::kstruct {

    public:

        block_t(kaitai::kstream* p__io, gif_t* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~block_t();

    private:
        block_type_t m_block_type;
        kaitai::kstruct* m_body;
        bool n_body;

    public:
        bool _is_null_body() { body(); return n_body; };

    private:
        gif_t* m__root;
        gif_t* m__parent;

    public:
        block_type_t block_type() const { return m_block_type; }
        kaitai::kstruct* body() const { return m_body; }
        gif_t* _root() const { return m__root; }
        gif_t* _parent() const { return m__parent; }
    };

    /**
     * \sa - section 19
     */

    class color_table_t : public kaitai::kstruct {

    public:

        color_table_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~color_table_t();

    private:
        std::vector<color_table_entry_t*>* m_entries;
        gif_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        std::vector<color_table_entry_t*>* entries() const { return m_entries; }
        gif_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    /**
     * \sa - section 17
     */

    class header_t : public kaitai::kstruct {

    public:

        header_t(kaitai::kstream* p__io, gif_t* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~header_t();

    private:
        std::string m_magic;
        std::string m_version;
        gif_t* m__root;
        gif_t* m__parent;

    public:
        std::string magic() const { return m_magic; }
        std::string version() const { return m_version; }
        gif_t* _root() const { return m__root; }
        gif_t* _parent() const { return m__parent; }
    };

    /**
     * \sa - section 23
     */

    class ext_graphic_control_t : public kaitai::kstruct {

    public:

        ext_graphic_control_t(kaitai::kstream* p__io, gif_t::extension_t* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~ext_graphic_control_t();

    private:
        bool f_transparent_color_flag;
        bool m_transparent_color_flag;

    public:
        bool transparent_color_flag();

    private:
        bool f_user_input_flag;
        bool m_user_input_flag;

    public:
        bool user_input_flag();

    private:
        std::string m_block_size;
        uint8_t m_flags;
        uint16_t m_delay_time;
        uint8_t m_transparent_idx;
        std::string m_terminator;
        gif_t* m__root;
        gif_t::extension_t* m__parent;

    public:
        std::string block_size() const { return m_block_size; }
        uint8_t flags() const { return m_flags; }
        uint16_t delay_time() const { return m_delay_time; }
        uint8_t transparent_idx() const { return m_transparent_idx; }
        std::string terminator() const { return m_terminator; }
        gif_t* _root() const { return m__root; }
        gif_t::extension_t* _parent() const { return m__parent; }
    };

    class subblock_t : public kaitai::kstruct {

    public:

        subblock_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~subblock_t();

    private:
        uint8_t m_num_bytes;
        std::string m_bytes;
        gif_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        uint8_t num_bytes() const { return m_num_bytes; }
        std::string bytes() const { return m_bytes; }
        gif_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class ext_application_t : public kaitai::kstruct {

    public:

        ext_application_t(kaitai::kstream* p__io, gif_t::extension_t* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~ext_application_t();

    private:
        subblock_t* m_application_id;
        std::vector<subblock_t*>* m_subblocks;
        gif_t* m__root;
        gif_t::extension_t* m__parent;

    public:
        subblock_t* application_id() const { return m_application_id; }
        std::vector<subblock_t*>* subblocks() const { return m_subblocks; }
        gif_t* _root() const { return m__root; }
        gif_t::extension_t* _parent() const { return m__parent; }
    };

    class subblocks_t : public kaitai::kstruct {

    public:

        subblocks_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~subblocks_t();

    private:
        std::vector<subblock_t*>* m_entries;
        gif_t* m__root;
        kaitai::kstruct* m__parent;

    public:
        std::vector<subblock_t*>* entries() const { return m_entries; }
        gif_t* _root() const { return m__root; }
        kaitai::kstruct* _parent() const { return m__parent; }
    };

    class extension_t : public kaitai::kstruct {

    public:

        extension_t(kaitai::kstream* p__io, gif_t::block_t* p__parent = 0, gif_t* p__root = 0);

    private:
        void _read();

    public:
        ~extension_t();

    private:
        extension_label_t m_label;
        kaitai::kstruct* m_body;
        gif_t* m__root;
        gif_t::block_t* m__parent;

    public:
        extension_label_t label() const { return m_label; }
        kaitai::kstruct* body() const { return m_body; }
        gif_t* _root() const { return m__root; }
        gif_t::block_t* _parent() const { return m__parent; }
    };

private:
    header_t* m_hdr;
    logical_screen_descriptor_struct_t* m_logical_screen_descriptor;
    color_table_t* m_global_color_table;
    bool n_global_color_table;

public:
    bool _is_null_global_color_table() { global_color_table(); return n_global_color_table; };

private:
    std::vector<block_t*>* m_blocks;
    gif_t* m__root;
    kaitai::kstruct* m__parent;
    std::string m__raw_global_color_table;
    bool n__raw_global_color_table;

public:
    bool _is_null__raw_global_color_table() { _raw_global_color_table(); return n__raw_global_color_table; };

private:
    kaitai::kstream* m__io__raw_global_color_table;

public:
    header_t* hdr() const { return m_hdr; }
    logical_screen_descriptor_struct_t* logical_screen_descriptor() const { return m_logical_screen_descriptor; }

    /**
     * \sa - section 18
     */
    color_table_t* global_color_table() const { return m_global_color_table; }
    std::vector<block_t*>* blocks() const { return m_blocks; }
    gif_t* _root() const { return m__root; }
    kaitai::kstruct* _parent() const { return m__parent; }
    std::string _raw_global_color_table() const { return m__raw_global_color_table; }
    kaitai::kstream* _io__raw_global_color_table() const { return m__io__raw_global_color_table; }
};

#endif  // GIF_H_
