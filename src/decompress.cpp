#include "utils.h"
bool decompress(const char * argv){

    std::ifstream ReadFile;
    ReadFile.exceptions(std::ios::failbit |std::ios::badbit);
    try
    {
        ReadFile.open(argv, std::ios::binary);

        // ReadFile.seekg(0, std::ios::end);
        // unsigned int file_size = ReadFile.tellg();
        // ReadFile.seekg(0, std::ios::beg);


    }
    catch(const std::ios_base::failure& e)
    {
        std::cerr <<"Error: the file("<<argv[1]<<") is corrupted or cannot be opened"<<'\n';
        std::cerr << "Reason: " << e.what() << '\n'<<"Code: "<<e.code() << '\n';
        return false;
    }
    char *huff;
    ReadFile.read(huff, 4);
    if (!(huff[0] == 'H' &&huff[1] == 'U' && huff[2] == 'F' && huff[3] == 'F'))
    {
        std::cerr<<"This file has the wrong extension. (not huff)"<<std::endl;
        return false;
    }
    char filename_size;
    char * filename;



    ReadFile.read(&filename_size,1);
    ReadFile.read(filename,filename_size);
    std::vector<Bits> vector_table = ReadTable(ReadFile);


    // maybe add check file doubled with ifstream 
    std::ofstream WriteFile;
    WriteFile.open(filename, std::ios::binary);
    if (!WriteFile.is_open())
    {
        std::cerr <<"Error: the file("<<argv<<") is corrupted or cannot be opened"<<'\n';
        return false;
    }

    
    
    

}