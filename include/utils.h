#ifndef UTILS
#define UTILS

#include "includes.h"
typedef std::map<char, std::string> Table;

struct Node {
    int freq;
    char ch;
    Node * left = nullptr;
    Node * right = nullptr;
    Node(char ch, int freq) : ch(ch), freq(freq){};
    Node (char ch, int freq, Node * left, Node * right) : ch(ch), freq(freq), left(left), right(right){};
};
struct  compare
{
    bool operator()(const Node *a, const Node * b ){
        return a->freq > b->freq;
    }
};

template<typename T1, typename T2>
std::map<T2, T1> SwapKeyValue(const std::map<T1, T2> & input){
    std::map<T2, T1> result;
    for( const auto & it : input){
        result.emplace(it.second, it.first);        
    }
    return result;
}

void FreeTree(Node *& root);



void WriteCodes(Node * root, const std::string & str, std::map<char, std::string> &CodesTable);
std::map<char, std::string> GetTable(const std::string &str);
std::string GetCompressedString(const std::string & str, const std::map<char, std::string> & CodesTable);


std::pair<std::string, std::map<char, std::string>> CompressData(const std::string & text);



void WriteTableData(std::ofstream & file, const std::map<char, std::string> &table);
void WriteCompressedText(std::ofstream & file, const std::string & data);

bool compress(const char * argv);

// remake
std::string decode(const std::string& bin_str, const std::map<char, std::string> & CodeTable);



#endif