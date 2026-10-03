#include "utils.h"
std::string GetCompressedString(const std::string & str, const std::map<char, std::string> & CodesTable){
    std::string Binary_str;
    for (const char & ch : str){
        Binary_str += (*CodesTable.find(ch)).second;
    }
    return Binary_str;
}