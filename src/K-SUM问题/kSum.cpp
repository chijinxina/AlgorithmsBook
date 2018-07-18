//
// Created by chijinxin on 18-7-16.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
/*
 * 1. 找出和为定值的任意多个数字
 * 算法思想：
 * 考虑是否取第n个数字，问题可以转化为前n-1个数字和为 sum-a[n-1]的问题
 * ``如果取第n个数，即求得前n-1个数字满足和为sum-a[n-1]的问题
 * ``如果不取第n个数字，即求得前n-1个数满足和为sum的问题
 */
class solution{
public:
    list<int> result;

    void sumOfnumbers(vector<int> &nums, int n, int target)
    {
        if(n<=0 || target<=0) return;  //边界条件 递归出口

        //找到了需要的数字
        if(target == nums[n])
        {
            for_each(result.begin(),result.end(),
                     [](int x)
                     {
                         cout<<x<<"+";
                     });
            cout<<nums[n]<<endl;    //注意当前数字还没添加到里面
        }

        result.push_front(nums[n]);
        sumOfnumbers(nums,n-1,target-nums[n]);   //将第n个数放到里面
        result.pop_front();
        sumOfnumbers(nums,n-1,target);           //第n个数不放在里面
    }
};




/*
 * 2. k个和为定值的个数
 * 动态规划
 */


int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10};
    solution s1;
    s1.sumOfnumbers(nums,nums.size()-1,15);

    return 0;
}
