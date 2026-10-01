#include "utils.h"
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