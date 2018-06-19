//
// Created by chijinxin on 18-6-19.
//
#include <iostream>
#include <memory.h>
using namespace std;

/*
 * 筛素数
 */
int flag[1000000/32];


void GetPrime(int n)  //n 素数上限
{
    memset(flag,0, sizeof(flag));

    flag[0] |= 1;   //0不是素数
    flag[0] |= (1<<1);   //1不是素数

    for(int i=2;i<=n;i++)
    {
        for(int k=2*i;k<=n;k+=i)
        {
            flag[k/32] |= (1<<(k%32));
        }
    }

}

int main()
{
    GetPrime(100);
    for(int i=0;i<100;i++)
    {
        if(!(flag[i/32]&(1<<(i%32))))  //是素数
        {
            cout<<i<<" "<<" ";
        }
    }
    return 0;
}
