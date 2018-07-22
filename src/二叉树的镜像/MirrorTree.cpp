//
// Created by chijinxin on 18-7-22.
//
#include <iostream>
#include <stack>
#include <Tree33.hpp>
using namespace std;
/*
 *             5
 *         /      \
 *        3        7
 *     /     \       \
 *    1       4       9
 *
 *    求二叉树的镜像
 */

//递归实现二叉树的镜；按照先序遍历，如果遇到空的节点或者叶子节点为空就返回，否则交换两个子树后再改变左右子树
void MirrorBinaryTree (TreeNode* root)
{
    if( root==NULL || (root->left == NULL && root->right == NULL) )
    {
        return;
    }

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    if(root->left)
    {
        MirrorBinaryTree(root->left);
    }
    if(root->right)
    {
        MirrorBinaryTree(root->right);
    }
}



//非递归前序遍历
void preOrder(TreeNode* root)
{
    stack<TreeNode*> ss;
    TreeNode* current = root;
    while(current != NULL || !ss.empty())
    {
        while(current!=NULL)
        {
            cout<<current->val<<" ";
            ss.push(current);
            current = current->left;
        }
        if(!ss.empty())
        {
            current = ss.top();
            ss.pop();
            current = current->right;
        }
    }
}
void preOrder_difui(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->val<<" ";
    preOrder_difui(root->left);
    preOrder_difui(root->right);
}

//非递归中序遍历
void inOrder(TreeNode* root)
{
    stack<TreeNode*> ss;
    TreeNode* current = root;
    while(current!=NULL || !ss.empty())
    {
        while(current!=NULL)
        {
            ss.push(current);
            current = current->left;
        }
        if(!ss.empty())
        {
            current = ss.top();
            ss.pop();
            cout<<current->val<<" ";
            current = current->right;
        }
    }
}

void inOrder_digui(TreeNode* root)
{
    if(root==NULL) return;
    inOrder_digui(root->left);
    cout<<root->val<<" ";
    inOrder_digui(root->right);
}

//非递归后序遍历
void postOrder(TreeNode* root)
{
    stack<TreeNode*> ss;
    TreeNode* current = root;  //当前节点
    TreeNode* previous = NULL; //前一个节点
    ss.push(current);
    while (!ss.empty())
    {
        current = ss.top();
        //两种情况下直接访问节点，并将节点出栈
        //1. 当前节点的左右子树为空
        //2. 当前节点的左右孩子均被访问过了
        if((current->left==NULL && current->right==NULL)
           ||(previous!=NULL && (previous==current->left || previous==current->right)))
        {
            cout<<current->val<<" ";
            ss.pop();
            previous = current;
        }
        //不满足上述两种情况，则将当前节点的右 左 孩子依次入栈
        else
        {
            if(current->right!=NULL)
            {
                ss.push(current->right);
            }
            if(current->left!=NULL)
            {
                ss.push(current->left);
            }
        }
    }
}

void postOrder_digui(TreeNode* root)
{
    if(root==NULL) return;
    postOrder_digui(root->left);
    postOrder_digui(root->right);
    cout<<root->val<<" ";
}

int main()
{
    Tree t;
    MirrorBinaryTree(t.root);
//    preOrder(t.root);
//    cout<<endl;
//    preOrder_difui(t.root);
//    inOrder(t.root);
//    cout<<endl;
//    inOrder_digui(t.root);
    postOrder(t.root);
    cout<<endl;
    postOrder_digui(t.root);
    return 0;
}
