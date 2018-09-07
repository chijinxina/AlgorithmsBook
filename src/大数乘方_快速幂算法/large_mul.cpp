//
// Created by chijinxin on 18-9-7.
//
#include <iostream>
#include <string.h>
using namespace std;

void reverse_str(char* a, int size)
{
    for(int i=0; i<size/2; ++i)
    {
        char t = a[i];
        a[i] = a[size-1 - i];
        a[size-1 - i] = t;
    }
}

void large_mul(char a[], char b[], char c[])
{
    char a_t[10000] = {0};
    char b_t[10000] = {0};
    char c_t[20000] = {0};
    strcpy(a_t, a);
    strcpy(b_t, b);
    int a_len = strlen(a_t);
    int b_len = strlen(b_t);
    reverse_str(a_t, a_len);
    reverse_str(b_t, b_len);
    for(int i=0; i<b_len; ++i)
    {
        for(int j=0; j<a_len; ++j)
        {
            int k = i+j;
            c_t[k] += (a_t[j]-'0')*(b_t[i]-'0');
            //进位
            if(c_t[k] > 9)
            {
                c_t[k+1] += (c_t[k]/10);
                c_t[k] = c_t[k]%10;
            }
        }
    }
    int j=0;
    for (j = a_len+b_len;  j>0 ; --j)
    {
        if(c_t[j] != 0) break;
    }
    c_t[j+1] = '\0';  //字符串结束
    for(int i=j; i>=0; --i)
    {
        c_t[i] = c_t[i] + '0';
    }
    reverse_str(c_t, strlen(c_t));
    strcpy(c, c_t);
}

void large_mul_pro(int m, int n, char c[])
{
    strcpy(c,"1");
    char a[100000] = {0};
  //  char b[100] = {0};
    int i=0;
    while(m>0)
    {
        a[i++] = m%10 + '0';
        m /= 10;
    }
    reverse_str(a, strlen(a));
    //快速幂算法
    while(n!=0)
    {
        if(n&1) large_mul(a,c,c);
        large_mul(a,a,a);
        n >>= 1;
    }

}

int main()
{
    char a[10] = "1234";
    char b[10] = "129";
    char c[100000]={0};
    //large_mul(a,b,c);
    large_mul_pro(1234,77,c);

    cout<<c<<endl;
    //large_mul(a,b,c);
    return 0;
}

