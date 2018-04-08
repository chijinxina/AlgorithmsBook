//
// Created by chijinxin on 18-4-8.
//大数阶乘
//
#include <iostream>
#include <memory.h>
using namespace std;

int a[100]={0};  //100位长度的大数

int computeFact(int n) //返回大数的位数
{
    int result=0;
    int current=0;
    memset(a,0,sizeof(a));
    a[0] = 1; //第一个数字为1
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=result;j++)
        {
            a[j] *= i;

        }
    }
    return result;

}

int main()
{
    int re = computeFact(4);
    for(int i=re;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}
