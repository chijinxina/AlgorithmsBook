//
// Created by chijinxin on 17-9-17.
//
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int dp[100][100];

int LCS1(int d[100][100],int n, int m)
{
    return d[n][m];
}

int main(){
    string a,b;
    int n,m;
    while (cin>>a>>b)
    {
        n=a.length();
        m=b.length();
        cout<<n<<" "<<m<<endl;
        cout<<LCS1(dp,1,2)<<endl;
    }
    return 0;
}

