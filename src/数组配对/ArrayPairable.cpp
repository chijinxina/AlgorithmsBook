//
// Created by chijinxin on 18-4-16.
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
 * 《给定 N（偶数）个整数,是否能找到 N/2 对，使得每对的和能被 k 整除》
 *
 *  如果某个数能被 k 整除，那么该数对 num % k == 0 假设 a 和 b 之和能被 k 整除 即 （a+b）%k==0
 *  a%k==z if(z==0) {b%k = 0}
 *         if(z!=0) {b%k = k-z}
 */
bool checkPairable(vector<int> &arr, int k)
{
    if(k==1) return true;
    if(arr.size()==0) return false;

    unordered_map<int,int> yushu;

    for(int i=0;i<arr.size();i++)
    {
        if(yushu.find(arr[i]%k)==yushu.end())
        {
            yushu.insert(make_pair(arr[i]%k,1));
        }
        else
        {
            yushu[arr[i]%k]++;
        }
    }

    /*
     * 边界条件
     * 1. 能被k整除的个数为奇数 则不满足条件
     */
    if(yushu[0]%2!=0) return false;
    /*
     * 2. 如果k为偶数，那么查看余数为k/2的个数是否为偶数 如果余数是k/2的个数为奇数 则不能满足条件
     */
    if(k%2==2 && yushu[k/2]%2!=0) return false;

    /*
     * 3.余数配对
     */
    bool flag = true;
    for(int i=1;i<=k/2;i++)
    {
        if(yushu[i]!=yushu[k-i])
        {
            flag=false;
            break;
        }
    }
    return flag;
}

int main()
{
    vector<int> arr={1,1,2,2,3,3,4,4,5,5};
    cout<<checkPairable(arr,2);
    return 0;
}