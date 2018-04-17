//
// Created by chijinxin on 18-4-17.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
 * 快排分区函数 （寻找最小的k个数字 O(n)）
 * 选择一个基准数，将数组分为两部分，把小于等于基准数的数字移动到数组左边，把比选中的比基准数大的数移动到数组的右边
 * 返回分区后的基准数字所在的下标
 */

int partition2(vector<int> &vec, int start, int end)
{
    int pivot = vec[start]; //基准数字

    while (start<end)
    {
        while (start<end && pivot<=vec[end])  end--;

        vec[start] = vec[end];

        while (start<end && pivot>=vec[start]) start++;

        vec[end] = vec[start];
    }
    vec[start] = pivot;
    return start;
}




int main()
{
    vector<int> data={3,4,3,1,8,10,12,4,5,7,11,22};
    int k=6;
    int n = data.size()-1;
    int index = partition2(data, 0, n);
    int left=0,right=n;
    while(index!=(k-1))
    {
        if(index > k-1)
        {
            right = index - 1;
            index = partition2(data, left, right);
        }
        else if(index < k-1)
        {
            left = index + 1;
            index = partition2(data, left, right);
        }
    }

    for(int i=0;i<k;i++)
    {
        cout<<data[i]<<" ";
    }


    return 0;
}
