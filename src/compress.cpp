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

    std::string filename = argv;

    auto file_erase_it = std::find(filename.rbegin(), filename.rend(),'/');
    if (file_erase_it != filename.rend()) 
        filename.erase(filename.begin(), file_erase_it.base());

    char length = filename.length();
    WriteFile.put(length);
    WriteFile.write(filename.c_str(), length);

    WriteTableData(WriteFile, result.second);
    WriteCompressedText(WriteFile, result.first);
    WriteFile.close();
    return true;
}