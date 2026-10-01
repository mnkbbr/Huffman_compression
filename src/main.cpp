#include "utils.h"

int main(){
    std::string text = "Rand text for compression";
    auto result = compress(text);
    std::cout<<"Compressed string:\n"<<result.first<<std::endl;
    std::cout<<"\nDecode Message:\n";
    std::cout<<decode(result.first, result.second);
    std::cout<<"\n\ncompressed "<<(text.size() * 8) - result.first.size() << "bits ("<<text.size() - (result.first.size() / 8)<<" bytes)"<< std::endl;
}
