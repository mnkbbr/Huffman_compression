#include "utils.h"
void WriteCompressedText(std::ofstream & file, const std::string & data){
    size_t data_length = data.length();
    file.write((char*)&data_length, sizeof(data_length));
    char buffer = 0;
    int bit_counter = 0;
    for(auto i = data.begin(); i != data.end(); ++i){
        if (*i == '1')
        {
            buffer |= (1 << (7-bit_counter));
        }
        ++bit_counter;
        if (bit_counter == 8)
        {
            file.put(buffer);
            buffer = bit_counter = 0;
        }
    }
    if (bit_counter != 0)
    {
        //buffer = buffer << (7-bit_counter);
        file.put(buffer);
    }
}