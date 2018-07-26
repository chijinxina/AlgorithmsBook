//
// Created by chijinxin on 18-7-26.
//
#include <iostream>
#include <stack>
#include <vector>

using namespace std;
/*
 * 有序数组转为二叉搜索树
 */

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v),left(NULL),right(NULL)
    {}
};




TreeNode* SortArrayToBST(vector<int> &array, int l, int r)
{
    if(array.size()==0) return NULL;

    if(l > r) return NULL;

    else
    {
        int mid = l + (r - l)/2;
        TreeNode* current = new TreeNode(array[mid]);
        current->left = SortArrayToBST(array, l, mid-1);
        current->right= SortArrayToBST(array, mid+1, r);
        return current;
    }
}

/*
 * 二叉树非递归前序遍历
 */
void preOrder(TreeNode* root)
{
    stack<TreeNode*> s;
    TreeNode* current = root;
    while(current!=NULL || !s.empty())
    {
        while (current!=NULL)
        {
            cout<<current->val<<" ";
            s.push(current);
            current = current->left;
        }
        if(!s.empty())
        {
            current = s.top();
            s.pop();
            current = current->right;
        }
    }
}

void preOrder_d(TreeNode* root)
{
    if(root==NULL) return;
    cout<<root->val<<" ";
    preOrder_d(root->left);
    preOrder_d(root->right);
}
void inOrder(TreeNode* root)
{
    if(root==NULL) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}


int main()
{
    vector<int> aaa{1,2,3,4,5,6,7,8,9};
    TreeNode* root = SortArrayToBST(aaa, 0, aaa.size()-1);
    cout<<"非递归前序遍历：";
    preOrder_d(root);
    cout<<endl<<" 递归前序遍历：";
    preOrder(root);
    cout<<endl<<"   中序遍历：";
    inOrder(root);
    return 0;
}
