//,
// Created by chijinxin on 18-7-30.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * 利用std::partition函数实现快速排序
 */
void QSort_partition(vector<int>::iterator left, vector<int>::iterator right)
{
    if(left >= right) return;
    vector<int>::iterator mid = std::partition(left,right,
            [left](const int &x)
            {
                if(x <= *left) return true;
                else return false;
            });
    iter_swap(mid-1, left);
    QSort_partition(left,mid-1);
    QSort_partition(mid,right);
}

int main()
{
    vector<int> aaa = {2,1,6,9,4,1,3,4,5,6,12};
    QSort_partition(aaa.begin(),aaa.end());
    for(int &x : aaa)
    {
        cout<<x<<" ";
    }
    return 0;
}
