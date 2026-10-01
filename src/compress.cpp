#include "utils.h"
std::pair<std::string, std::map<char, std::string>> compress(const std::string & text){
    auto Table = GetTable(text);
    std::string CompressedString = GetCompressedString(text, Table);
    return std::make_pair(CompressedString, Table);
}
