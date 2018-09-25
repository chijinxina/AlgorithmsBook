//
// Created by chijinxin on 18-9-25.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 * 假设A和B的元素个数都大于k/2，我们将A[k/2 - 1] 和 B[k/2 - 1] 进行比较，有以下三种情况：
 *      A[k/2 - 1] == B[k/2 - 1]
 *      A[k/2 - 1] > B[k/2 - 1]
 *      A[k/2 - 1] < B[k/2 - 1]  ->  意味着A[0]到A[k/2 - 1] 的肯定在A∪B的topK元素的范围内，也就是A[k/2 - 1]不可能大于A∪B的第K个元素
 *
 *      递归函数：
 *          1. 当A或B为空时，直接返回B[k-1]或A[k-1]
 *          2. 当k==1时， 返回min(A[0], B[0])
 *          3. 当A[k/2 - 1] == B[k/2 - 1]时， 返回A[k/2 - 1] 或者 B[k/2 - 1]
 */
int findKth(const vector<int> &A, const vector<int> &B, int i, int j, int m, int n, int k)
{
    if(m > n) return findKth(B,A,j,i,n,m,k);  //确保 A的长度 小于等于 B的长度
    if(m==0) return B[k-1];
    if(k==1) return min(A[i],B[j]);

    int ia = min(k/2,m);
    int ib = k - ia;
    if(A[i+ia-1] < B[j+ib-1])
    {
        return findKth(A,B,i+ia,j,m-ia,n,k-ia);
    }
    else if(A[i+ia-1] > B[i+ib-1])
    {
        return findKth(A,B,i,j+ib,m,n-ib,k-ib);
    }
    else return A[i+ia-1];
}

double findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    int m = A.size();
    int n = B.size();
    int total = m + n;
    if(total%2==1)
    {
        return findKth(A,B,0,0,m,n,total/2-1);
    }
    else
    {
        return (findKth(A,B,0,0,m,n,total/2) + findKth(A,B,0,0,m,n,total/2-1))/2.0;
    }
}

int main()
{
    vector<int> A{1,2,3,4,5,6,7};
    vector<int> B{1,2,3,4,5,6,7};
    cout<<findMedianSortedArrays(A,B)<<endl;
    return 0;
}
