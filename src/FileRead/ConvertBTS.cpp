#include "utils.h"
void ConvertBTS(std::vector<Bits> & vec){
    for (auto &el : vec){
        std::string num_str;
        for (size_t i = 0; i < el.number_of_bits; ++i)
        {
            num_str += ((el.compressed_char >> i) & 1) ? '1' : '0';
        }
        std::reverse(num_str.begin(), num_str.end());
        el.made_char = num_str;
        
    }
}