//
// Created by chijinxin on 18-8-12.
//
#include <iostream>
#include <vector>

using namespace std;
/*
 * 线段树  求区间最大值  最小值
 */
struct SegmentTreeNode{
    int start;
    int end;
    int min;
    int max;
    bool flag;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int s, int e):start(s),end(e),min(999999),max(0),left(NULL),right(NULL),flag(false){}
};

//构造线段树
SegmentTreeNode* BuildSegmentTree(vector<int> &vec, int start, int end)
{
    if(start > end) return NULL;
    SegmentTreeNode* root = new SegmentTreeNode(start, end);

    int mid = start + (end - start)/2;

    if(start != end)
    {
        root->left = BuildSegmentTree(vec, start, mid);
        root->right= BuildSegmentTree(vec, mid+1, end);
        root->max = std::max(root->left->max, root->right->max);
        root->min = std::min(root->left->min, root->right->min);
    }
    else
    {
        root->max = vec[start];
        root->min = vec[start];
    }
}

/*
 * 今日头条笔试题
 * 两个序列 a, b  存在多少个区间[l,r] 满足 max([a[l],a[r]) < min([b[l], b[r]])
 */
SegmentTreeNode* BuildSegmentTreeOfIntervals(vector<int> &a, vector<int> &b, int start, int end)
{
    if(start > end) return NULL;
    SegmentTreeNode* root = new SegmentTreeNode(start, end);
    int mid = start + (end - start)/2;

    if(start != end)
    {
        root->left = BuildSegmentTreeOfIntervals(a, b, start, mid);
        root->right= BuildSegmentTreeOfIntervals(a, b, mid+1, end);
        root->max = std::max(root->left->max, root->right->max);
        root->min = std::min(root->left->min, root->right->min);
        root->flag = root->max < root->min ? true : false;
    }
    else
    {
        root->max = a[start];
        root->min = b[start];
        root->flag = root->max < root->min ? true : false;
    }
}

void preOrder(SegmentTreeNode* root, vector<SegmentTreeNode*> &vec)
{
    if(root==NULL) return;
    if(root->flag) vec.push_back(root);
    preOrder(root->left, vec);
    preOrder(root->right, vec);
}

int main()
{
    vector<int> aaa = {1,2,3,4,5,6,7,8,9};
    vector<int> bbb = {10,9,8,7,6,5,4,3,2};
    SegmentTreeNode* root = BuildSegmentTree(aaa, 0, 8);
    cout<<root->max<<endl;
    SegmentTreeNode* root2= BuildSegmentTreeOfIntervals(aaa, bbb, 0, 8);

    vector<SegmentTreeNode*> result;
    preOrder(root2, result);
    cout<<result.size()<<endl;
    return 0;
}
