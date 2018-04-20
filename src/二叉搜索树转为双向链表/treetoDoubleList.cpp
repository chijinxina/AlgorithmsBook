//
// Created by chijinxin on 18-4-20.
//
#include <iostream>
#include "Tree33.hpp"
using namespace std;

/*
 * 修改中序遍历的过程，以获取双向链表节点的两个指针
 * 1. 记录头指针以便返回新的链表
 * 2. 每次有新的节点加入时，头指针需要建立和该节点的相互指向关系，以保证链表的收尾相接
 * 3. 为了充实双向链表指向后一节点的指针，我们还需要一个prev指针记录当前的位置，这个prev指针随节点的
 *    遍历移动，作为下一轮遍历节点的前一个节点
 */


void inOrderTravel(TreeNode* root, TreeNode* &prev, TreeNode* &head)
{
    if(root==NULL) return;

    inOrderTravel(root->left,prev,head);  //先递归遍历左子树

    root->left = prev; //当前节点的left指向前一个节点

    if(prev!=NULL)
    {
        prev->right = root; //前一个节点的right指向当前节点
    }
    else
    {
        head = root; //前一个节点不存在，说明当前节点是链表的头
    }

    TreeNode* right = root->right;  //!!!!!!提前记录右节点的值 因为后面会修改root->right的值

    /*将收尾相接 建立循环关系*/
    head->left = root;
    root->right= head; //!!!!!!（root->right指针被改变）应该提前保存该指针为后面的递归遍历右子树提供 当前指针的right

    //进入下一个节点之前，更新prev节点
    prev = root;

    inOrderTravel(right,prev,head);  //最后递归遍历右子树 !!!!!(right !not root->right)
}

TreeNode* treeToDoubleList(TreeNode* root)
{
    TreeNode* prev = NULL;
    TreeNode* head = NULL;
    inOrderTravel(root,prev,head);
    return head;
}


int main()
{
    Tree tt;
    //inOrderTravel(tt.root);
    TreeNode* head = treeToDoubleList(tt.root);
    cout<<"1"<<endl;
    return 0;
}
