#include "utils.h"
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
