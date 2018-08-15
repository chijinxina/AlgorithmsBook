//
// Created by chijinxin on 18-8-14.
//
#include <iostream>
using namespace std;
/*
 * 替换空格
 */
//len为字符数组str的总长度
void repalceSpace(char* str, int len)
{
    if(str == NULL || len <=0)
    {
        return;
    }
    int originlen = 0;    //原始字符串长度
    int numofspace= 0;    //空格数量
    int i = 0;
    while(str[i] != '\0')
    {
        ++originlen;
        //统计空格数量
        if(str[i]==' ')
            ++numofspace;
        ++i;
    }
    int newlen = originlen + 2*numofspace;
    if(newlen > len) return;

    int indexOfOri = originlen;
    int indexOfNew = newlen;
    while (indexOfOri >=0 && indexOfNew > indexOfOri)
    {
        if(str[indexOfOri] == ' ')
        {
            str[indexOfNew--] = '0';
            str[indexOfNew--] = '2';
            str[indexOfNew--] = '%';
        }
        else
        {
            str[indexOfNew--] = str[indexOfOri];
        }
        --indexOfOri;
    }
}


int main()
{
    char str[1000] = "my name is chijinxin";
    repalceSpace(str,1000);
    cout<<str<<endl;
    return 0;
}
