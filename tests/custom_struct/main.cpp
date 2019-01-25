#include <iostream>
#include <fstream>
#include <assert.h>
#include "custom_struct.h"


int main()
{
    std::fstream input_fstream("custom_struct1.dat", std::fstream::in | std::fstream::binary);
    kaitai::kstream kstream(&input_fstream);
    custom_struct_t custom_struct(&kstream);
    custom_struct._read();
    std::cout << "custom_struct.m_v_u1=" << custom_struct.m_v_u1 << std::endl;
    std::cout << "custom_struct.m_v_s1=" << custom_struct.m_v_s1 << std::endl;

    std::fstream output_fstream("custom_struct2.dat", std::fstream::out | std::fstream::binary);
    custom_struct._io()->set_stream(&output_fstream);
    custom_struct._write();

    input_fstream.close();
    output_fstream.close();
    input_fstream.open("custom_struct1.dat", std::fstream::in | std::fstream::binary);
    output_fstream.open("custom_struct2.dat", std::fstream::in | std::fstream::binary);
    input_fstream.seekg(0, input_fstream.end); int input_fstream_length = input_fstream.tellg(); input_fstream.seekg(0, input_fstream.beg);
    output_fstream.seekg(0, output_fstream.end); int output_fstream_length = output_fstream.tellg(); output_fstream.seekg(0, output_fstream.beg);
    assert(output_fstream_length == input_fstream_length);
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
