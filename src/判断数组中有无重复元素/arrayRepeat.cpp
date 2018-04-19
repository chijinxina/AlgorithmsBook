//
// Created by chijinxin on 18-4-18.
//
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

/*
 * 遍历数组，假设第i个位置的数字为j,则通过交换将j交换到下标为j的位置上，直到所有数字都出现在自己对应的下标处
 * 或发生冲突， 时间复杂度为O(n) 空间复杂度为O(1)
 */
int vec[1000]={0};
bool isArrayRepeat(vector<int> &a)
{
    int n = a.size();
    int i,j;
    memset(vec,0,sizeof(vec));

    for(i=0;i<n;i++)
    {
        j = a[i];
        if(i==j)
        {
            continue;
        }
        else
        {
            if(a[i]==vec[j])
                return true;
            else
                vec[j] = a[i];
        }
    }
    return false;
}


int main()
{
    vector<int> data={10,9,5,4,7,6,3,2,1,9};
    bool result = isArrayRepeat(data);
    if(result) {cout<<"Has repeat number!"<<endl;}
    else {cout<<"Hasn't repeat num!"<<endl;}
    return 0;
}
