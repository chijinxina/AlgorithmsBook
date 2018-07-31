//
// Created by chijinxin on 18-7-31.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * 递归法归并排序
 */

//将数组下标范围为[l1,r1]和[l2,r2]的有序序列合并为一个有序序列
void merge(vector<int> &vec, int l1, int r1, int l2, int r2)
{
    int i = l1;  //左半部分的起始位置
    int j = l2;  //右半部分的起始位置
    int n = (r1 - l1 + 1) + (r2 - l2 + 1);   //要合并的元素个数
    vector<int> temp(n);                     //初始化n个元素的辅助数组
    int k = 0;                               //辅助数组的起始位置

    while( i <= r1 && j <= r2)
    {
        //取小元素
        if(vec[i] < vec[j])
        {
            temp[k++] = vec[i++];
        }
        else
        {
            temp[k++] = vec[j++];
        }
    }
    //如果其中一个还有剩余的元素，直接放入辅助数组中去
    while(i <= r1)
    {
        temp[k++] = vec[i++];
    }
    while(j <= r2)
    {
        temp[k++] = vec[j++];
    }
    //更新原始数组元素
    for(int z=0; z < n; z++)
    {
        vec[l1+z] = temp[z];
    }
}

//递归二路归并排序
void MergeSort(vector<int> &vec, int start, int end)
{
    if(start >= end)  return;
    int mid = (start+end)>>1;
    MergeSort(vec, start, mid);
    MergeSort(vec,mid+1,end);
    merge(vec,start,mid,mid+1,end);
}

int main()
{
    vector<int> vec = {3,2,4,9,1,6,6,44,2,34,6,5};
    MergeSort(vec,0,vec.size()-1);
    for(int &x : vec)
    {
        cout<<x<<" ";
    }

    return 0;
}
