//
// Created by chijinxin on 18-7-28.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * 区间求和（利用线段树的构造和查询实现O(logn)时间复杂度的查询）
 */
class SegmentTreeNode{
public:
    int start;
    int end;
    long long sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
    SegmentTreeNode(int s, int e):start(s),end(e),sum(0),left(NULL),right(NULL){}
};

//线段树的构造
SegmentTreeNode* Build(vector<int> &vec, int start, int end)
{
    if(start > end) return NULL;
    SegmentTreeNode* root = new SegmentTreeNode(start,end);
    int mid = start + (end-start)/2;
    if(start!=end)
    {
        root->left = Build(vec, start, mid);
        root->right= Build(vec, mid+1, end);
        root->sum = root->left->sum + root->right->sum;
    }
    else
    {
        root->sum = vec[start];
    }
}


//线段树的查询
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


//区间定义
class Interval{
public:
    int start;
    int end;
    Interval(int s,int e):start(s),end(e){}
};
//区间求和
vector<long long> intervalSum(vector<int> &vec, vector<Interval> &queries)
{
    vector<long long> result;
    //构建线段树
    SegmentTreeNode* root = Build(vec,0,vec.size()-1);
    for(Interval q : queries)
    {
        result.push_back(query(root,q.start,q.end));
    }
    return result;
}


int main()
{
    vector<int> vec ={1,2,3,4,5,6,7,8,9};
    vector<Interval> q;
    q.emplace_back(0,1);
    q.emplace_back(1,2);
    q.emplace_back(2,3);
    q.emplace_back(0,3);
    q.emplace_back(0,8);

    vector<long long> ss = intervalSum(vec,q);
    for(int i=0;i<ss.size();i++)
    {
        cout<<ss[i]<<" ";
    }
//    for_each(ss.begin(),ss.end(),
//             [](long long x)
//             {
//                 cout<<x<<" ";
//             });

    return 0;
}
