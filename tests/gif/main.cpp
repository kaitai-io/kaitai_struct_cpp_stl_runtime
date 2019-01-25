#include <iostream>
#include <fstream>
#include <assert.h>
#include "gif.h"


int main()
{
    std::fstream input_fstream("gif1.gif", std::fstream::in | std::fstream::binary);
    kaitai::kstream kstream(&input_fstream);
    gif_t gif(&kstream);
    gif._read();
    std::cout << "input_gif.m_hdr->m_magic=" << gif.m_hdr->m_magic << std::endl;
    std::cout << "input_gif.m_hdr->m_version=" << gif.m_hdr->m_version << std::endl;
    std::cout << "input_gif.m_logical_screen_descriptor->m_screen_width=" << gif.m_logical_screen_descriptor->m_screen_width << std::endl;
    std::cout << "input_gif.m_logical_screen_descriptor->m_screen_height=" << gif.m_logical_screen_descriptor->m_screen_height << std::endl;
    std::cout << "input_gif.m_logical_screen_descriptor->m_flags=" << gif.m_logical_screen_descriptor->m_flags << std::endl;
    std::cout << "input_gif.m_logical_screen_descriptor->m_bg_color_index=" << gif.m_logical_screen_descriptor->m_bg_color_index << std::endl;
    std::cout << "input_gif.m_logical_screen_descriptor->m_has_color_table=" << gif.m_logical_screen_descriptor->m_has_color_table << std::endl;
    std::cout << "input_gif.m_logical_screen_descriptor->m_color_table_size=" << gif.m_logical_screen_descriptor->m_color_table_size << std::endl;
    if (gif.m_logical_screen_descriptor->m_has_color_table)
    {
        for (int i = 0; i < gif.m_global_color_table->m_entries->size(); ++i)
        {
            std::cout << "(*input_gif.m_global_color_table->m_entries)[i]->m_red=" << (*gif.m_global_color_table->m_entries)[i]->m_red << std::endl;
            std::cout << "(*input_gif.m_global_color_table->m_entries)[i]->m_green=" << (*gif.m_global_color_table->m_entries)[i]->m_green << std::endl;
            std::cout << "(*input_gif.m_global_color_table->m_entries)[i]->m_blue=" << (*gif.m_global_color_table->m_entries)[i]->m_blue << std::endl;
        }
    }
//    for (int i = 0; i < input_gif.m_blocks->size(); ++i)
//    {
//        std::cout << "(*input_gif.m_blocks)[i]->m_block_type=" << (*input_gif.m_blocks)[i]->m_block_type << std::endl;
//        switch ((*input_gif.m_blocks)[i]->m_block_type)
//        {
//        case gif_t::block_type_t::BLOCK_TYPE_EXTENSION:
//        {
//            std::cout << "dynamic_cast<gif_t::extension_t*>((*input_gif.m_blocks)[i]->m_body)->m_label=" << dynamic_cast<gif_t::extension_t*>((*input_gif.m_blocks)[i]->m_body)->m_label << std::endl;
//            switch (dynamic_cast<gif_t::extension_t*>((*input_gif.m_blocks)[i]->m_body)->m_label)
//            {
//            case gif_t::extension_label_t::EXTENSION_LABEL_APPLICATION:
//            {
//                std::cout << "dynamic_cast<gif_t::ext_application_t*>(dynamic_cast<gif_t::extension_t*>((*input_gif.m_blocks)[i]->m_body)->m_body)->m_application_id=" << dynamic_cast<gif_t::ext_application_t*>(dynamic_cast<gif_t::extension_t*>((*input_gif.m_blocks)[i]->m_body)->m_body)->m_application_id << std::endl;
//                break;
//            }
//            case gif_t::extension_label_t::EXTENSION_LABEL_COMMENT:
//            {
//                break;
//            }
//            case gif_t::extension_label_t::EXTENSION_LABEL_GRAPHIC_CONTROL:
//            {
//                break;
//            }
//            default:
//            {
//                break;
//            }
//            }
//            break;
//        }
//        case gif_t::block_type_t::BLOCK_TYPE_LOCAL_IMAGE_DESCRIPTOR:
//        {
//            break;
//        }
//        }
//    }

    std::fstream output_fstream("gif2.gif", std::fstream::out | std::fstream::binary);
    gif._io()->set_stream(&output_fstream);
    gif._write();

    input_fstream.close();
    output_fstream.close();
    input_fstream.open("gif1.gif", std::fstream::in | std::fstream::binary);
    output_fstream.open("gif2.gif", std::fstream::in | std::fstream::binary);
    input_fstream.seekg(0, input_fstream.end); int input_fstream_length = input_fstream.tellg(); input_fstream.seekg(0, input_fstream.beg);
    output_fstream.seekg(0, output_fstream.end); int output_fstream_length = output_fstream.tellg(); output_fstream.seekg(0, output_fstream.beg);
//    assert(output_fstream_length == input_fstream_length);
    char *input_data = new char[input_fstream_length];
    char *output_data = new char[output_fstream_length];
    input_fstream.read(input_data, input_fstream_length);
    output_fstream.read(output_data, output_fstream_length);
    for (int i = 0; i < output_fstream_length; ++i)
    {
        assert(output_data[i] == input_data[i]);
    }
    delete [] input_data;
    delete [] output_data;

    return 0;
}
