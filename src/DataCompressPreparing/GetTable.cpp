#include "utils.h"
std::map<char, std::string> GetTable(const std::string &str){
    std::map<char, unsigned int>  table;
    for (const char & ch : str ){
        auto TableElement = table.insert(std::make_pair(ch, 1));
        if (!TableElement.second) TableElement.first->second += 1;
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