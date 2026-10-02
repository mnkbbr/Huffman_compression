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