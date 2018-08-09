//
// Created by chijinxin on 18-8-9.
//
#include <iostream>
#include <vector>
#include "Tree33.hpp"

using namespace std;

void digui(TreeNode* root, vector<vector<int>> &Paths, vector<int> path)
{
    if(root->left == NULL && root->right == NULL)
    {
        Paths.push_back(path);
        //path.clear();
        return;
    }
    if(root->left != NULL)
    {
        path.push_back(root->left->val);
        digui(root->left, Paths, path);
    }
    if(root->right != NULL)
    {
        path.push_back(root->right->val);
        digui(root->right, Paths, path);
    }
}



vector<vector<int>> BTreePaths(TreeNode* root)
{
    vector<vector<int>> Paths;
    if(root==NULL) return Paths;
    vector<int> path;
    path.push_back(root->val);
    digui(root, Paths, path);
    return Paths;

}

void ff(TreeNode *root,vector<string>&Paths,string strPaths)
{
    if(root->left==NULL&&root->right==NULL)
    {
        Paths.push_back(strPaths);
        return;
    }
    if(root->left!=NULL)
        ff(root->left,Paths,strPaths+"->"+to_string(root->left->val) );
    if(root->right!=NULL)
        ff(root->right,Paths,strPaths+"->"+to_string(root->right->val) );

}
vector<string> binaryTreePaths(TreeNode* root) {
    // Write your code here
    vector<string>Paths;
    if(root==NULL) return Paths;
    ff(root,Paths,to_string(root->val) );
    return Paths;
}



public void findPath(Node root ,int n){
    if(root!=null)
    {
        stack.push(root);
        n = n-root.value;
        if(n==0 && root.left==null && root.right==null){
            for(Node no:stack){
                System.out.print(no.value);
            }
            System.out.println();
        }

        findPath(root.left, n);
        findPath(root.right, n);
        stack.pop();
    }



int main()
{
    Tree tree;
    vector<vector<int>> Paths1 = BTreePaths(tree.root);
    vector<string> Paths2 = binaryTreePaths(tree.root);
    cout<<endl;
    return 0;
}
