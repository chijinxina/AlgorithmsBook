//
// Created by chijinxin on 18-7-28.
//
#include <iostream>
#include <vector>

using namespace std;
/*
 * 线段树是一颗二叉树，它的每个节点包含了两个额外的属性 start和end用于代表该节点表示的区间
 * 1. 根节点的start和end由build方法给出
 * 2. 对于节点A的左孩子，有start = A.left , end = (A.left + A.right)/2
 * 3. 对于节点B的右孩子，有start = (A.left + A.right)/2 , end = A.right
 * 4. 如果start==end， 那么该节点是叶子节点，不再有左右孩子
 */


//线段树节点定义
class SegmentTreeNode {
public:
    int start;
    int end;
    long long sum;    //区间和
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int s, int e) : start(s), end(e), left(NULL), right(NULL), sum(0){}
};

//根据vector构造线段树
SegmentTreeNode* Build(vector<int> &vec, int start, int end)
{
    if(start > end)
    {
        return NULL;
    }
    SegmentTreeNode* root = new SegmentTreeNode(start,end);  //根节点
    if(start != end)
    {
        int mid = start + (end - start)/2;
        root->left = Build(vec, start, mid);
        root->right= Build(vec, mid+1, end);
        root->sum = root->left->sum + root->right->sum;
    }
    else
    {
        root->sum = vec[start];
    }
    return root;
}


/*
 * 线段树的查询操作
 */
long long query(SegmentTreeNode* root, int start, int end)
{
    if(root==NULL || start>end)
        return 0;
    if(start <= root->start && end >= root->end)
        return root->sum;

    int mid = (root->start + root->end)/2;
    if(start > mid)
        return query(root->right,start,end);

    else if(end < mid+1)
        return query(root->left,start,end);
    else
        return query(root->left,start,mid) + query(root->right, mid+1, end);
}


int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    SegmentTreeNode* root = Build(vec,0,vec.size()-1);
    cout<<query(root,0,2)<<endl;
    return 0;
}
