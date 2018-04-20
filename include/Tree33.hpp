#include <iostream>
using namespace std;



class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v),left(NULL),right(NULL) {}
};

class Tree{
public:
    TreeNode* root;
    Tree()
    {
        root = new TreeNode(5);
        TreeNode* n11 = new TreeNode(3);
        TreeNode* n12 = new TreeNode(7);
        root->left = n11;
        root->right= n12;
        TreeNode* n21 = new TreeNode(1);
        TreeNode* n22 = new TreeNode(4);
        n11->left = n21;
        n11->right= n22;
        TreeNode* n23 = new TreeNode(9);
        n21->left = NULL; n21->right=NULL;
        n22->left = NULL; n22->right=NULL;

        n12->left = NULL;

        n23->left = NULL; n23->right=NULL;
    }

};