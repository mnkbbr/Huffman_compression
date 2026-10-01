#include "utils.h"

int main(int argc, const char ** argv){
    unsigned int TextLength;
    std::string text;

    if (argc < 2 || argc > 2)
    {
        std::cout<<"./Huff <file_path>"<<std::endl;
    }
    
    std::ifstream ReadFile;
    ReadFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try
    {
        ReadFile.open(argv[1]);
        char ch;
        ReadFile.exceptions(std::ifstream::badbit);
        while (ReadFile.get(ch))
        {
            text += ch;
        }
        TextLength = text.length();
        ReadFile.close();
    }
    catch(const std::ios_base::failure& e)
    {
        std::cerr <<"Error: the file("<<argv[1]<<") is corrupted or cannot be opened"<<'\n';
        std::cerr << "Reason: " << e.what() << '\n'<<"Code: "<<e.code() << '\n';
        return -1;
    }
    auto result = compress(text);
    unsigned int TableSize = result.second.size();
    std::ofstream WriteFile;
    WriteFile.open("compressed.huff");
    if (!WriteFile.is_open())
    {
        std::cerr <<"Error: the file("<<argv[1]<<") is corrupted or cannot be opened"<<'\n';
        return -1;
    }
    WriteTableData(WriteFile, result.second);
    
    
    
    
}
