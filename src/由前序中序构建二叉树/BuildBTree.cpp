//
// Created by chijinxin on 18-8-8.
//
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v){}
};

TreeNode* BuildBTree(vector<int> pre, vector<int> in)
{
    if(pre.empty() || in.empty()) return NULL;

    TreeNode* node = new TreeNode(pre[0]);
    for(int i=0;i<in.size();i++)
    {
        if(pre[0] == in[i])
        {
            vector<int> pre_l(pre.begin()+1, pre.begin()+i+1);
            vector<int> pre_r(pre.begin()+i+1, pre.end());
            vector<int> in_l(in.begin(),in.begin()+i);
            vector<int> in_r(in.begin()+i+1,in.end());
            node->left = BuildBTree(pre_l,in_l);
            node->right= BuildBTree(pre_r,in_r);
            break;
        }
    }
    return node;
}

void postOrder(TreeNode* root)
{
    if(root==NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
}

int main()
{
    vector<int> pre = {6,4,2,5,3,1,7};
    vector<int> in ={4,2,5,6,1,3,7};
    TreeNode* root = BuildBTree(pre,in);
    postOrder(root);


    return 0;
}


