#include "utils.h"

int main(int argc, const char ** argv){

    if (argc < 3 || argc > 3)
    {
        std::cout<<"./Huff <flag> <file_path>\n"<<std::endl;
        std::cout<<"Flags:\n";
        std::cout<<"-c for compress file\n-d for decompress file"<<std::endl;
        return 0;
    }
    if (argv[1] == "-c")
    {
        if (!compress(argv[2])) return -1;
    }
    else if (argv[1] == "-d")
    {
        //WIP
    }

}

/*   compressed file architecture
*
*
*
*    first 4 bytes - HUFF - extension code
*
*    1 byte - file_name_size 
*    file_name_size bytes - file_name
*
*    2 bytes table_size
*    table_size *
*     {
*      1 byte - number_of_bits
*      1-4 bytes - compressed_char
*      1 byte - char
*     } 
*    bytes
*
*    8 bytes(size_t) - compressed_data_size
*    compressed_data_size bytes  - compressed_data
*
*
*
*/ 
