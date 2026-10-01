#include "utils.h"
std::string decode(const std::string& bin_str,  const std::map<char, std::string> & CodeTable){
    std::string correct_str;
    std::string acc;
    const std::map<std::string, char> BinTable = SwapKeyValue(CodeTable);
    for (const char &ch : bin_str){
        acc += ch;
        auto it = BinTable.find(acc);
        if (it == BinTable.end()) continue;
        else {
            correct_str += (*it).second;
            acc.clear(); 
        }
    }
    return correct_str;
}
