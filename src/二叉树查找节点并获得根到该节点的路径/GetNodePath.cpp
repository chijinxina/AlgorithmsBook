//
// Created by chijinxin on 18-6-29.
//
#include <iostream>
#include <stack>
#include <Tree33.hpp>
using namespace std;

/*
 * 查找二叉树的指定节点及根节点到该节点的路径
 * 利用后序遍历的思想
 * 后续的搜索每条路径，并将每条路径经过的节点压栈
 * 当该路径上没有要要寻找的节点时，将路径上的节点依次退栈
 */

bool GetNodePath(TreeNode* root, TreeNode* findNode, stack<TreeNode*> &s)
{
    if(root==NULL) return false;
    if(root==findNode)              //找到了节点
    {
        return true;
    }
    bool found = false;                //查找到节点
    s.push(root);                   //先将当前节点压栈
    if(root->left!=NULL)
    {
        found = GetNodePath(root->left,findNode,s);
    }
    if(!found && root->right!=NULL)
    {
        found = GetNodePath(root->right,findNode,s);
    }

    //如果此路径没有找到，出栈
    if(!found)
    {
        s.pop();
    }
    return found;
}


int main()
{
    Tree t;
    stack<TreeNode*> path;
    GetNodePath(t.root,t.root->right->right,path);
    while(!path.empty())
    {
        cout<<path.top()->val<<" ";
        path.pop();
    }
    return 0;
}
