#include "utils.h"
std::vector<Bits> ReadTable(std::ifstream & ReadFile){
    unsigned short int table_size;
    ReadFile.read((char*)&table_size, 2);

    std::vector<Bits> vec;
    vec.resize(table_size);

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        auto &tmp = *it;
        ReadFile.read(&tmp.number_of_bits, 1);

        if (tmp.number_of_bits > 24)ReadFile.read((char*)tmp.compressed_char, 4);
        else if(tmp.number_of_bits > 16)ReadFile.read((char*)&tmp.compressed_char, 3);
        else if(tmp.number_of_bits > 8) ReadFile.read((char*)&tmp.compressed_char, 2);
        else ReadFile.read((char*)&tmp.compressed_char, 1);
        ReadFile.read(&tmp.ch, 1);
    }
    ConvertBTS(vec);
    return vec;
    
}