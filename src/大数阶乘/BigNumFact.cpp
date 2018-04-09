//
// Created by chijinxin on 18-4-8.
//大数阶乘
//
#include <iostream>
#include <memory.h>
using namespace std;

int a[100000]={0};  //100位长度的大数

int computeFact(int n) //返回大数的位数
{
    int result=0;
    int current=0;
    memset(a,0,sizeof(a));
    a[0] = 1; //第一个数字为1
    int jin=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=result;j++)
        {
            a[j] = a[j]*i + jin;
            if(a[j]>=10)
            {
                jin = a[j]/10;
                a[j]=a[j]%10;
                if(j==result)
                {
                    result++;
                }
            }
            else
            {
                jin = 0;
            }
        }
    }
    return result;

}

int main()
{

    int m;
    while(cin>>m)
    {
        int re = computeFact(m);
        for(int i=re;i>=0;i--)
        {
            cout<<a[i];
        }
        cout<<endl;
    }

    return 0;
}
