//
// Created by chijinxin on 18-4-9.
//
#include <iostream>
#include <string.h>

using namespace std;

int dp[50][50]={0};

int LCS2(const string &a,const string &b,int n,int m)
{
    memset(dp[0],0,sizeof(dp[0]));
    for(int i=0;i<50;i++)
    {
        dp[i][0]=0;
    }
    int max=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i-1]==b[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                if(dp[i][j]>max)
                    max = dp[i][j];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return max;
}

int main()
{
    string a,b;
    while(getline(cin,a))
    {
        getline(cin,b);
        cout<<LCS2(a,b,a.length(),b.length())<<endl;
    }
    return 0;
}
