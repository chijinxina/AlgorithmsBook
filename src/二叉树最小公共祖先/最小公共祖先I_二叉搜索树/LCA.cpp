//
// Created by chijinxin on 18-4-20.
//
#include <iostream>
#include "Tree33.hpp"
using namespace std;

/*
 * 给定两个节点，求它们在一颗二叉搜索树中的最小公共祖先
 *
 * 利用二叉搜索树的特点（节点的值大于其左子树的值，小于其右子树的值，因此两个节点间的最小公共祖先的值一定介于这两个节点值之间）
 * 通过前序遍历二叉搜索树来判断最小公共祖先出现在左子树还是右子树，还是节点本身。
 */

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==NULL || p==NULL || q==NULL) return NULL;
    //1. 最小公共祖先在左子树
    if(root->val > p->val && root->val > q->val)
    {
        return LCA(root->left,p,q);
    }
    //2. 最小公共祖先在右子树
    else if(root->val < p->val && root->val < q->val)
    {
        return LCA(root->right,p,q);
    }
    //3. 返回节点本身
    else
    {
        return root;
    }
}

int main()
{
    Tree tt;



    TreeNode* lca = LCA(tt.root,tt.p,tt.q);
    cout<<lca->val<<endl;

    return 0;
}
