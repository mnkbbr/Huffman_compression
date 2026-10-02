#include "utils.h"
void WriteTableData(std::ofstream & file, const std::map<char, std::string> & table){
    unsigned short int TableSize = table.size();
    file.write((char*)&TableSize, sizeof(TableSize));
    for (const auto & el : table){
        unsigned short int compressedvalue = 0;
        char bitsize = 0;
        for (auto i = el.second.crbegin(); i != el.second.crend(); ++i)
        {
            // if (counter > 8) add dynamic size
            // {

            // }
            
            if (*i == '1')
            {
                compressedvalue |= (1<<bitsize);
                ++bitsize;
            }
            else {
                ++bitsize;
            }
        }
        file<<bitsize;
        file.write((char*)&compressedvalue, sizeof(compressedvalue));
        file<<el.first;
        bitsize = 0;
        compressedvalue = 0;
    }
}