//
// Created by chijinxin on 18-4-13.
//
#include <iostream>
using namespace std;


/*
 * 非递归版
 */
int gcd(int x, int y)
{
    if(x % y == 0) return y;
    while(x!=0 && y!=0)
    {
        x = x % y;
        y = y % x;
    }
    return x=0?y:x;
}

/*
 * 递归版
 */
int gcd_d(int x, int y)
{
    if(x % y == 0)
        return y;
    else
        return gcd(y,x%y);
}


int main()
{
    cout<<gcd_d(12,8)<<endl;
    return 0;
}
