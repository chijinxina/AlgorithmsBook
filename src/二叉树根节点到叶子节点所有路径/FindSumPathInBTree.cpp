//
// Created by chijinxin on 18-8-13.
//
#include <iostream>
#include <vector>
#include "Tree33.hpp"
using namespace std;
/*
 * 查找二叉树中和为某一值的路径
 */
void FindPath(TreeNode* root, int num, vector<int> &path, vector<vector<int>> &paths)
{
    if(root==NULL) return;
    path.push_back(root->val);
    num -= root->val;
    if(num==0 && root->left==NULL && root->right==NULL)
    {
        paths.push_back(path);
    }
    FindPath(root->left, num, path, paths);
    FindPath(root->right, num, path, paths);
    path.pop_back();
}

int main()
{
    Tree t;
    vector<int> path;
    vector<vector<int>> paths;
    FindPath(t.root, 9, path, paths);
    return 0;
}
