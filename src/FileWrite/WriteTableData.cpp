#include "utils.h"
#define WriteByte(i, value, bitsize) if (*i == '1'){value |= (1<<bitsize);++bitsize;}else{++bitsize;}
void WriteTableData(std::ofstream & file, const std::map<char, std::string> & table){
    unsigned short int TableSize = table.size();
    file.write((char*)&TableSize, sizeof(TableSize));
    for (const auto & el : table){

        int value4b=0;
        char bitsize = 0;
        for (auto i = el.second.crbegin(); i != el.second.crend(); ++i)
        {
            if (*i == '1')
            {
                value4b |= (1<<bitsize);
                ++bitsize;
            }
            else {
                ++bitsize;
            }
        }
        file.put(bitsize);

        if (bitsize > 24)file.write((char*)&value4b, 4);
        else if(bitsize > 16)file.write((char*)&value4b, 3);
        else if(bitsize > 8) file.write((char*)&value4b, 2);
        else file.write((char*)&value4b, 1);
        
        file.put(el.first);
    }
}