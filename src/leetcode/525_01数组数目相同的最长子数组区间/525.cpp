//
// Created by chijinxin on 18-9-12.
//
#include <iostream>
#include <map>
#include <vector>
using namespace std;

//子数组之和与结尾位置的坐标之间的映射
int findMaxLength(vector<int> &nums)
{
    int res = 0, n = nums.size(), sum = 0;
    //利用hashmap建立子数组之和跟结尾位置坐标之间的映射关系
    map<int, int> M{{0,-1}}; //第一维sum 第二维index
    for(int i=0; i<n; i++)
    {
        //将子数组的和与01的个数产生联系
        //trick 遇1加1 遇0减1， 如果某个子数组的和为0，说明0和1的个数相等
        sum += (nums[i]==1)?1:-1;
        if(M.count(sum))
        {
            res = max(res, i-M[sum]);   //i - M[sum] 两个坐标索引相减
        }
        else
        {
            M[sum] = i;
        }
    }
    return res;
}


int main()
{
    vector<int> vec{0,1,0};
    cout<<findMaxLength(vec)<<endl;
    return 0;
}
