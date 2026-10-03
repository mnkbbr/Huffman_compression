#include "utils.h"
void ReadWriteData(std::ifstream & ReadFile, const std::vector<Bits> &BitsTable, std::ofstream & WriteFile){
    size_t compressed_data_size;
    ReadFile.read((char*)&compressed_data_size, sizeof(size_t));

    size_t bits_counter = 0;
    std::string acc_buffer ;
    char buffer = 0;

    ReadFile.exceptions(std::ios::goodbit);

    while (ReadFile.read(&buffer, 1))
    {        
        for (int buf_pos = 0;buf_pos < 8; buf_pos++) // replace counter
        {
            char bit = (((buffer) >> (7 - buf_pos)) & 1) ? '1' : '0' ;
            ++bits_counter;

            acc_buffer += bit;
            
            auto result_char = std::find_if(BitsTable.begin(), BitsTable.end(),[&](const Bits & el){
                return acc_buffer == el.made_char;
            });
            if (result_char != BitsTable.end())
            {
                acc_buffer.clear();
                WriteFile.put(result_char->ch);
            }
            if (bits_counter == compressed_data_size) return;
        }
    }
}
