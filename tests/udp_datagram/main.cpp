#include <iostream>
#include <fstream>
#include <assert.h>
#include "udp_datagram.h"


int main()
{
    std::fstream input_fstream("udp_datagram1.dat", std::fstream::in | std::fstream::binary);
    kaitai::kstream kstream(&input_fstream);
    udp_datagram_t udp_datagram(&kstream);
    udp_datagram._read();
    std::cout << "udp_datagram.m_src_port=" << udp_datagram.m_src_port << std::endl;
    std::cout << "udp_datagram.m_dst_port=" << udp_datagram.m_dst_port << std::endl;
    std::cout << "udp_datagram.m_length=" << udp_datagram.m_length << std::endl;
    std::cout << "udp_datagram.m_checksum=" << udp_datagram.m_checksum << std::endl;
    std::cout << "udp_datagram.m_body=" << udp_datagram.m_body << std::endl;

    std::fstream output_fstream("udp_datagram2.dat", std::fstream::out | std::fstream::binary);
    udp_datagram._io()->set_stream(&output_fstream);
    udp_datagram._write();

    input_fstream.close();
    output_fstream.close();
    input_fstream.open("udp_datagram1.dat", std::fstream::in | std::fstream::binary);
    output_fstream.open("udp_datagram2.dat", std::fstream::in | std::fstream::binary);
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
