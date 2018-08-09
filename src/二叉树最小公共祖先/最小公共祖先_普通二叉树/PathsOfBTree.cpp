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

    public int minNumberInRotateArray(int [] array)
    {

        if(array == null)
            return 0;
        int i = 0, j = array.length - 1, mid = 0;
        while(array[i] >= array[j])
        {
            if(j-i==1)
            {
                mid = j;
                break;
            }

            mid = (i+j)/2;
            //如果array[i]==array[j]==array[mid]
            //则不能用二分查找，因为不确定array[mid]位于哪个有序子数组
            //只能用顺序查找
            if(array[i]==array[j]&&array[j]==array[mid])
            {
                //在除了Main()方法中调用其他方法需要new实例之外，其他方法中调用同一个类中的方法直接用：方法名（实参）即可，不需要其他操作
                return findInOrder(array,i,j);
            }

            if(array[i]<=array[mid])
                i=mid;
            else if(array[mid]<=array[j])
                j=mid;
        }
        return array[mid];
    }
    //顺序查找
    public int findInOrder(int[] a, int in1, int in2)
    {
        int k = a[in1];
        for(int i = in1+1; i < in2; i++)
            if(a[i]<k)
                k=a[i];
        return k;
    }



int main()
{
    Tree tree;
    vector<vector<int>> Paths1 = BTreePaths(tree.root);
    vector<string> Paths2 = binaryTreePaths(tree.root);
    cout<<endl;
    return 0;
}
