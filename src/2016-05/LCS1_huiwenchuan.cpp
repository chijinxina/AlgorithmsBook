//
// Created by chijinxin on 2017/9/18.
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


//给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
//输出需要删除的字符个数。
//提到回文串，自然要利用回文串的特点，想到将源字符串逆转后，“回文串”（不一定连续）相当于顺序没变
//求原字符串和其反串的最大公共子序列（不是子串，因为可以不连续）的长度（使用动态规划很容易求得），
// 然后用原字符串的长度减去这个最大公共子串的长度就得到了最小编辑长度。
int main(){
    string a;
    while (cin>>a)
    {
        string b(a);
        reverse(b.begin(),b.end());  //b等于a的反转字符串
        int len = LCS1(a,b);//字符串和其反转字符串的最长公共子序列
        int result = a.length() - len;//删除最少的字符个数 得到的回文串最长
        cout<<result<<endl;
    }
    return 0;
}


