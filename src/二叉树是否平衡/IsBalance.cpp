//
// Created by chijinxin on 18-9-17.
//
#include <iostream>
#include <Tree33.hpp>
using namespace std;

/*
 * 计算二叉树深度
 * 复杂度较高 多次遍历
 */
int height(TreeNode* root)
{
    if(root==NULL) return 0;
    int left_height = height(root->left);
    int right_height = height(root->right);
    return 1 + (right_height > left_height ? right_height : left_height);
}

/*
 * 计算二叉树深度 (采用后序遍历的方法）
 * 判断二叉树是否平衡
 */
bool IsBalance(TreeNode* root, int &depth)
{
    if(root==NULL)
    {
        depth = 0;
        return true;
    }
    int left, right;
    if(IsBalance(root->left, left) && IsBalance(root->right, right))
    {
        if(abs(left - right) <=1 )
        {
            depth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}

int main()
{
    return 0;
}
