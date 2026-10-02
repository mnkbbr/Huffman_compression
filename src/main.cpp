#include "utils.h"

int main(int argc, const char ** argv){
    std::string text;

    if (argc < 2 || argc > 2)
    {
        std::cout<<"./Huff <file_path>"<<std::endl;
        return 0;
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
        ReadFile.close();
    }
    catch(const std::ios_base::failure& e)
    {
        std::cerr <<"Error: the file("<<argv[1]<<") is corrupted or cannot be opened"<<'\n';
        std::cerr << "Reason: " << e.what() << '\n'<<"Code: "<<e.code() << '\n';
        return -1;
    }
    auto result = compress(text);

    std::ofstream WriteFile;
    WriteFile.open("compressed.huff");
    if (!WriteFile.is_open())
    {
        std::cerr <<"Error: the file("<<argv[1]<<") is corrupted or cannot be opened"<<'\n';
        return -1;
    }
    WriteFile<<"HUFF";
    WriteTableData(WriteFile, result.second);
    
    
    
    
}
