#include <iostream>
#include <queue>
#include <map>
#include <string>
#include <algorithm>

struct Node {
    int freq;
    char ch;
    Node * left = nullptr;
    Node * right = nullptr;
    Node (char ch, int freq) : ch(ch), freq(freq){};
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

void FreeTree(Node *& root){
    if (!root->left && !root->right)
    {
        delete root;
        return;
    }
    FreeTree(root->left);
    FreeTree(root->right);
    delete root;
    
} 

void WriteCodes(Node * root, const std::string & str, std::map<char, std::string> &CodesTable){
    
    // found leaf
    if (!root->left && !root->right)
    {
        CodesTable[root->ch] = str;
        return;
    }
    WriteCodes(root->left, str + '0', CodesTable);
    WriteCodes(root->right, str + '1', CodesTable);
}
std::map<char, std::string> GetTable(const std::string &str){
    std::map<char, unsigned int>  table;
    for (const char & ch : str ){
        auto a = table.insert(std::make_pair(ch, 1));
        if (!a.second){
            auto &tmp = *a.first;
            tmp.second += 1;
        }
    }

    std::priority_queue<Node *, std::vector<Node *>, compare> pq;
    Node * root;
    std::map<char, std::string> CodesTable;

    for (const auto &el: table){
        pq.push(new Node(el.first, el.second));
    }
    table.clear();
    
    if (pq.size() == 1)
    {
        root = pq.top();
        WriteCodes(root,"0",CodesTable); 

        FreeTree(root);

        return CodesTable;
    }
    
    while (pq.size() != 1)
    {
        Node * left = pq.top();
        pq.pop();
        Node * right = pq.top();
        pq.pop();
        pq.push(new Node('\0',left->freq+right->freq, left, right));
    }

    root = pq.top();
    WriteCodes(root,"",CodesTable); 
    
    FreeTree(root);

    return CodesTable;
}
std::string GetCompressedString(const std::string & str, const std::map<char, std::string> & CodesTable){
    std::string Binary_str;
    for (const char & ch : str){
        Binary_str += (*CodesTable.find(ch)).second;
    }
    return Binary_str;
}
std::pair<std::string, std::map<char, std::string>> compress(const std::string & text){
    auto Table = GetTable(text);
    std::string CompressedString = GetCompressedString(text, Table);
    return std::make_pair(CompressedString, Table);
}

std::string decode(const std::string& bin_str,  const std::map<char, std::string> & CodeTable){
    std::string correct_str;
    std::string acc;
    const std::map<std::string, char> BinTable = SwapKeyValue(CodeTable);
    for (const char &ch : bin_str){
        acc += ch;
        auto it = BinTable.find(acc);
        if (it == BinTable.end())
        {
            continue;
        }
        else {
            correct_str += (*it).second;
            acc.clear(); 
        }
    }
    return correct_str;

}



void PrintTable(const std::map<char, std::string> & CodesTable){
    std::vector<std::pair<char, std::string>> sortedTable;
    std::copy(CodesTable.begin(), CodesTable.end(), std::back_inserter(sortedTable)); 
    
    std::sort(sortedTable.begin(), sortedTable.end(),
    [](std::pair<char, std::string> pair, std::pair<char, std::string> pair2){
        return pair.second.size() < pair2.second.size();
    });
    for (const auto & elem : sortedTable){
        std::cout<<elem.first <<" "<< elem.second<<std::endl;
    }
}

int main(){
    std::string text = "Rand text for compression";
    auto result = compress(text);
    PrintTable(result.second);
    std::cout<<"Compressed string:\n"<<result.first<<std::endl;
    std::cout<<"\nDecode Message:\n";
    std::cout<<decode(result.first, result.second);
    std::cout<<"\n\ncompressed "<<(text.size() * 8) - result.first.size() << "bits ("<<text.size() - (result.first.size() / 8)<<" bytes)"<< std::endl;
}
