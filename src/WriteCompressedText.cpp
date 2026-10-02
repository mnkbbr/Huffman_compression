#include "utils.h"
void WriteCompressedText(std::ofstream & file, const std::pair<std::string, Table> & data){
    auto CodesTable = SwapKeyValue(data.second);
    size_t data_length = data.first.length();

}