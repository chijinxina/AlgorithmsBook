//
// Created by chijinxin on 18-8-13.
//
#include <iostream>
#include <vector>
#include "Tree33.hpp"
using namespace std;
/*
 * 获取二叉树根节点到叶子节点的所有路径
 */
void GetPathsOfBTree(TreeNode* root, vector<vector<int>> &paths, vector<int> &path)
{
    if(root==NULL) return;
    path.push_back(root->val);
    GetPathsOfBTree(root->left, paths, path);
    if(root->left==NULL && root->right==NULL) 
    {
        paths.push_back(path);
    }
    GetPathsOfBTree(root->right, paths, path);
    path.pop_back();
}

int main()
{
    Tree t;
    vector<int> path;
    vector<vector<int>> paths;
    GetPathsOfBTree(t.root, paths, path);
    return 0;
}
