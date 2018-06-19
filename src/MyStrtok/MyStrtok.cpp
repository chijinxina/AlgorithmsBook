//
// Created by chijinxin on 18-6-19.
//
#include <iostream>
#include <string.h>

using namespace std;

/*
 * strtok()原型： char* strtok(char *str, const char * delimiters);
 */

char * MyStrtok_base(char *str, const char* delimiters, char** temp_str)
{
    //定义一个指针来指向待分解的字符串
    char *b_temp;
    //1. 判断str是否为空
    if(str==NULL)
    {
        str = *temp_str;  //如果str为空就以传进来的temp_str为起始位置
    }
    //2. 跳过待分解字符串，扫描delimiters字符开始的所有分解符
    str += strspn(str, delimiters);
    //3. 判断当前待分解的位置是否为'\0'，若是则返回NULL,否则继续
    if(*str=='\0')
    {
        return NULL;
    }
    //4. 保存当前的待分解串的指针b_temp，调用strpbrk()在b_temp中找分解符
    //如果找不到，则将temp_str赋值为待分解字符串末尾部'\0'的位置，b_temp没有发生变化
    //如果找到，则将分解符所在的位置赋值为'\0'，b_temp相当于被截断了，temp_str指向分解符的下一位置
    b_temp = str;
    str = strpbrk(str,delimiters);
    if(str==NULL)
    {
        *temp_str = strchr(b_temp,'\0');
    }
    else
    {
        *str = '\0';
        *temp_str = str +1;
    }
    //5. 函数最后部分无论找没找到分解符，都将b_temp返回
    return b_temp;
}


char* MyStrtok(char *str, const char* delimiters)
{
    static char* temp_str;
    return MyStrtok_base(str,delimiters,&temp_str);
}

int main()
{
    char buf[]="hello@boy@this@is@heima";

    char *temp = MyStrtok(buf,"@");
    while(temp)
    {
        cout<<temp<<endl;
        temp = MyStrtok(NULL,"@");
    }

    return 0;
}
