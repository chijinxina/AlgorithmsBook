//
// Created by chijinxin on 18-4-7.
//
#include <iostream>
#include <algorithm>

using namespace std;

int a[10] = {2,8,1,4,3,5,10,9,6,7};

void QuickSort(int a[], int n, int left, int right)
{
    int i=left;
    int j=right; //左右哨兵
    int benchmark = a[left]; //基准数指向最左边的元素
    if(left>=right) return; //递归出口
    while(i!=j)
    {
        //1. 先从右向左找到小于基准数的元素
        while(a[j]>=benchmark && j>i) j--;
        //2. 从左向右找到大于基准数的元素
        while(a[i]<=benchmark && j>i) i++;
        //3. 交换a[j]和a[i]
        if(i<j)
        {
            a[j] ^= a[i];
            a[i] ^= a[j];
            a[j] ^= a[i];
        }
    }
    //4. 基准数归位
    a[left] = a[i];
    a[i] = benchmark;
    QuickSort(a,n,left,i-1);
    QuickSort(a,n,i+1,right);
}


int main()
{
    for_each(a,a+10,[](int x){cout<<x<<" ";});
    cout<<endl;
    //HeadSort(a,10);
    QuickSort(a,10,0,9);
    for_each(a,a+10,[](int x){cout<<x<<" ";});
    return 0;
}
