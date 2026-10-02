#include "utils.h"
bool compress(const char * argv){
    std::string text;
    std::ifstream ReadFile;
    ReadFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        ReadFile.open(argv, std::ios::binary);
        char ch;
        ReadFile.exceptions(std::ifstream::badbit);
        while (ReadFile.get(ch))
        {
            text += ch;
        }
        ReadFile.close();
    }
    catch(const std::ios_base::failure& e)
    {
        std::cerr <<"Error: the file("<<argv[1]<<") is corrupted or cannot be opened"<<'\n';
        std::cerr << "Reason: " << e.what() << '\n'<<"Code: "<<e.code() << '\n';
        return false;
    }
    auto result = CompressData(text);

    std::ofstream WriteFile;
    WriteFile.open("compressed.huff", std::ios::binary);
    if (!WriteFile.is_open())
    {
        std::cerr <<"Error: the file("<<argv[1]<<") is corrupted or cannot be opened"<<'\n';
        return false;
    }
    WriteFile.write("HUFF", 4);
    WriteTableData(WriteFile, result.second);
    WriteCompressedText(WriteFile, result.first);
    return true;
}