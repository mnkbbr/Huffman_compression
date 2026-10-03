#include "utils.h"
std::string ReadCompressedText(std::ifstream & ReadFile, const std::vector<Bits> &BitsTable, std::ofstream & WriteFile){

    std::string data;

    size_t compressed_data_size;
    ReadFile.read((char*)&compressed_data_size, sizeof(size_t));

    char buf_pos = 0;
    int acc_buffer = ~0;
    while (!ReadFile.eof())
    {
        char buffer = 0;
        ReadFile.read(&buffer,1);
        while (true) // replace counter
        {
            acc_buffer &= (buffer) >> (7 - buf_pos);

        }
    

}
