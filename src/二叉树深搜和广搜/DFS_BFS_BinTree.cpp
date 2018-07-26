//
// Created by chijinxin on 18-6-29.
//
#include <iostream>
#include <stack>
#include <queue>
#include <Tree33.hpp>
using namespace std;

/*
 * 二叉树的深度优先遍历
 * 利用栈实现，先将右子树压栈，再将左子树压栈
 */
void DepthFirstSearch(TreeNode* root)
{
    stack<TreeNode*> s;
    s.push(root);

    while(!s.empty())
    {
        TreeNode* current = s.top();
        cout<<current->val<<" ";
        s.pop();
        //先将右子数压栈 ！！！
        if(current->right!=NULL)
        {
            s.push(current->right);
        }
        //再将左子树压栈  ！！！
        if(current->left!=NULL)
        {
            s.push(current->left);
        }
    }
}

/*
 * 二叉树的广度优先遍历
 * 用一个队列实现
 */
void BreadthFirstSearch(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode* current = q.front();
        cout<<current->val<<" ";
        q.pop();
        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL)
        {
            q.push(current->right);
        }
    }
}




int main()
{
    cout<<"DFS:"<<endl;
    Tree t;
    DepthFirstSearch(t.root);
    cout<<endl<<"BFS:"<<endl;
    BreadthFirstSearch(t.root);
    return 0;
}
