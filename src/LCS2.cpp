#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int dp[100][100];//dp[i][j] -> 以a[i-1]和b[j-1]结尾的最长共同子串的长度

int LCS2(string &a,string &b,int n,int m)
{
    memset(dp,0,sizeof(dp));
    int max=0;
    for (int i = 1; i <=n ; ++i) {
        for (int j=1;j<=m;++j){
            if(a[i-1]==b[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if(dp[i][j]>max) max=dp[i][j];
            }
            else
                dp[i][j]=0;
        }
    }
    return max;
}

int main(){
    string a,b;

    int n,m;
    while(cin>>a>>b)
    {
        n=a.length();
        m=b.length();
        cout<<LCS2(a,b,n,m)<<endl;
    }
    return 0;
}
