//
// Created by chijinxin on 18-6-19.
//
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

//计算next数组
void cal_next(char* str, int* next, int len)
{
    vector<int> ca;
    next[0] = -1; //next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀
    int k = -1; //k初始化为-1
    for(int i=1; i<len; i++)
    {
        while(k>-1 && str[k+1]!=str[i])  //如果下一个不相同，那么k就变成next[k],注意next[k]是小于k的，无论k取任何值
        {
            k = next[k];  //往前回朔
        }
        if(str[k+1] == str[i])  //如果相同，k++
        {
            k++;
        }
        next[i] = k;  //算出的k的值（即相同的最大前缀和最大后缀的长度）赋值给next[i]
        ca.push_back(next[i]);
    }
}

//KMP算法
int KMP(char* str, int slen, char* ptr, int plen)
{
    int* next = new int[plen];
    cal_next(ptr,next,plen);  //计算next数组
    int k = -1;
    for(int i=0;i<slen;i++)
    {
        while(k>-1 && ptr[k+1]!=str[i])
        {
            k = next[k];    //往前回朔
        }
        if(ptr[k+1] == str[i])  //当前字符匹配成功
        {
            k++;
        }
        if(k==plen-1)    //全部匹配成功
        {
            return i-plen+1;
        }
    }
}

int main()
{
//    char *str = "bacbababadababacambabacaddababacasdsd";
//    char *ptr = "ababaca";
//    int a = KMP(str, 36, ptr, 7);
    char* bbb = "abcdabc";
    char* aaa = "abaabcac";

    int c = KMP(bbb, 7, aaa, 8);


   // cout<<a<<endl;
    return 0;
}