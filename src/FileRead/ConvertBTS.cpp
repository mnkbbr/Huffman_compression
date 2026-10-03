#include "utils.h"
void ConvertBTS(std::vector<Bits> & vec){
    for (auto &el : vec){
        std::string num_str;
        for (size_t i = 0; i < el.number_of_bits; ++i)
        {
            num_str += ((el.compressed_char >> 31-i) & 1) ? '1' : '0';
        }
        el.made_char = num_str;
        
    }
}