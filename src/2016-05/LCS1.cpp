//
// Created by chijinxin on 17-9-17.
//
#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

int dp[100][100];

int LCS1(string &a,string &b)
{
    int n=a.length();
    int m=b.length();
    memset(dp,0, sizeof(dp));
    for(int i=1;i<=n;++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
        }
    }
    return dp[n][m];
}

int main(){
    string aaa;
    while(cin>>aaa)
    {
        string bbb(aaa);
        reverse(bbb.begin(),bbb.end());
        int a=LCS1(aaa,bbb);
        cout<<
    }
    return 0;
}

