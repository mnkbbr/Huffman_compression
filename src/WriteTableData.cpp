#include "utils.h"
void WriteTableData(std::ofstream & file, const std::map<char, std::string> & table){
    unsigned short int TableSize = table.size();
    file.write((char*)&TableSize, sizeof(TableSize));
    for (const auto & el : table){
        unsigned short int compressedvalue;
        char bitsize = 0;
        unsigned short int counter = 0;
        for (auto i = el.second.crbegin(); i != el.second.crend(); ++i)
        {
            // if (counter > 8) add dynamic size
            // {

            // }
            
            if (*i == '1')
            {
                compressedvalue |= (1<<counter);
                ++counter;
                ++bitsize;
            }
            else {
                ++counter;
                ++bitsize;
            }
        }
        file<<bitsize;
        file.write((char*)&compressedvalue, sizeof(compressedvalue));
        file<<el.first;
    }
}