//
// Created by chijinxin on 18-8-13.
//
#include <iostream>
#include <string>
#include <sstream>
#include "Tree33.hpp"
#include <typeinfo>
using namespace std;
/*
 * 二叉树的序列化
 */

void SerializeBTree(TreeNode* root, string &result)
{
    if(root==NULL)
    {
        result.append("$ ");
        return;
    }
    result.append(to_string(root->val));
    result.append(" ");
    SerializeBTree(root->left, result);
    SerializeBTree(root->right, result);
}

/*
 * 二叉树的反序列化
 */
TreeNode* DeSerializeBTree(istringstream &in)
{
    string val;
    in >> val;
    if(val == "$")
    {
        return NULL;
    }

    TreeNode* root = new TreeNode(atoi(val.c_str()));
    root->left = DeSerializeBTree(in);
    root->right= DeSerializeBTree(in);
    return root;
}



int main()
{
    Tree t;
    string result;
    SerializeBTree(t.root, result);
    cout<<result<<endl;

    istringstream in(result);
    TreeNode* root = DeSerializeBTree(in);
    cout<<root->val<<endl;

    return 0;
}
