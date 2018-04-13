//
// Created by chijinxin on 18-4-11.
//
#include <iostream>
#include <vector>
using namespace std;

int min(int a,int b,int c)
{
    int m = a<b?a:b;
    return m<c?m:c;
}

int GetUglyNumber_Solution(int index)
{
    if(index<=1) return index;
    vector<int> ugly;
    ugly.push_back(1);
    int T2=0,T3=0,T5=0;
    int nextnum=1;
    while(nextnum<index)
    {
        int m = min(ugly[T2]*2,ugly[T3]*3,ugly[T5]*5);
        ugly.push_back(m);
        if(ugly[T2]*2 <= m)
        {
            T2++;
        }
        if(ugly[T3]*3 <= m)
        {
            T3++;
        }
        if(ugly[T5]*5 <= m)
        {
            T5++;
        }
        ++nextnum;
    }
    return ugly[index-1];
}

int main()
{
    cout<<GetUglyNumber_Solution(10)<<endl;
    return 0;
}
