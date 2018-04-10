//
// Created by chijinxin on 2017/9/18.
/*
 * 最短编辑距离问题
 */
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int dp[100][100];

int LCS1(string &a,string &b,int n,int m)
{
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

//由字符串 s1 通过下列三种操作
//　1、插入一个字符；
//  2、删除一个字符；
//　3、改变一个字符
//        字符串s1变换到字符串 s2 所需要的最少操作次数（亦即最短编辑距离问题）
//        max(s2的长度,s1的长度)-LCS1(s1,s2)
int main(){
    string a,b;
    int n,m;
    while(cin>>n>>a>>m>>b)
    {
        cout<<max(n,m)-LCS1(a,b,n,m)<<endl;
    }
    return 0;
}
