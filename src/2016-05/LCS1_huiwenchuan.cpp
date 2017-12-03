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


//����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
//�����Ҫɾ�����ַ�������
//�ᵽ���Ĵ�����ȻҪ���û��Ĵ����ص㣬�뵽��Դ�ַ�����ת�󣬡����Ĵ�������һ���������൱��˳��û��
//��ԭ�ַ������䷴������󹫹������У������Ӵ�����Ϊ���Բ��������ĳ��ȣ�ʹ�ö�̬�滮��������ã���
// Ȼ����ԭ�ַ����ĳ��ȼ�ȥ�����󹫹��Ӵ��ĳ��Ⱦ͵õ�����С�༭���ȡ�
int main(){
    string a;
    while (cin>>a)
    {
        string b(a);
        reverse(b.begin(),b.end());  //b����a�ķ�ת�ַ���
        int len = LCS1(a,b);//�ַ������䷴ת�ַ����������������
        int result = a.length() - len;//ɾ�����ٵ��ַ����� �õ��Ļ��Ĵ��
        cout<<result<<endl;
    }
    return 0;
}


