//
// Created by chijinxin on 18-9-25.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <list>

using namespace std;

//2Sum
vector<int> twosum(const vector<int> &nums, int target)
{
    vector<int> result;
    if(nums.size()<2) return result;
    unordered_map<int,int> mp;
    for(int i=0;i<nums.size();i++)
    {
        //找到了能够组合成target的数字
        if(mp.find(nums[i]) != mp.end())
        {
            result.push_back(mp[target-nums[i]]);
            result.push_back(i);
            break;
        }
        else
        {
            mp.insert(make_pair(target-nums[i], i));
        }
    }
    return result;
}

//3Sum
vector<vector<int>> threeSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    if(nums.size() < 3) return result;
    sort(nums.begin(),nums.end());
    for(int i=0; i<nums.size()-2;++i)
    {
        int j = i+1;
        //去除重复数字
        if(i>0 && nums[i]==nums[i-1]) continue;
        int k = nums.size()-1;

        while(j<k)
        {
            if(nums[i] + nums[j] + nums[k] < target)
            {
                ++j;
                while(nums[j]==nums[j-1] && j<k) ++j;//去重
            }
            else if(nums[i] + nums[j] + nums[k] > target)
            {
                --k;
                while(nums[k]==nums[k+1] && j<k) --k; //去重
            }
            else
            {
                result.push_back({nums[i],nums[j],nums[k]});
                ++j;
                --k;
                //去除重复数字
                while(nums[j]==nums[j-1] && nums[k]==nums[k+1] && j<k) ++j;
            }
        }
    }
    return result;
}


/*
 * ksum问题
 * 找出和为定值的任意多个数字 类似于背包问题
 * 算法思想：
 *      考虑是否取第n个数字,问题可以转化为前n-1个数字和为sum-nums[n-1]的问题
 *      1. 如果取第n个数字，即求得前n-1个数字满足和为sum-nums[n-1]
 *      2. 如果不取第n个数字，即求得前n-1个数字满足和为sum
 */
void kSum(vector<int> &nums, int n, int target, list<int> &res, vector<vector<int>> &result)
{
    if(n<0 || target<0) return;

    //找到了和为定值的数字
    if(target == nums[n])
    {
        vector<int> ress;
        for(int x : res)
        {
            ress.push_back(x);
            //cout<<x<<"+";
        }
        //cout<<nums[n]<<endl;
        ress.push_back(nums[n]);
        result.push_back(ress);
    }

    res.push_front(nums[n]);  //取第n个数字
    kSum(nums, n-1, target-nums[n], res, result);
    res.pop_front();
    kSum(nums, n-1, target,res, result);  //不取第n个数字
}


int main()
{
    vector<int> nums{2,7,11,15};
    vector<int> res = twosum(nums,13);
    for(int x:res)
    {
        cout<<x<<" ";
    }

    vector<int> nums2{-1,0,1,2,-1,-4};
    vector<vector<int>> res2 = threeSum(nums2,0);

    vector<int> data{1,2,3,4,5,6,7,8};
    list<int> ress;
    vector<vector<int>> result;
    kSum(data, data.size()-1, 6 ,ress, result);
    return 0;
}
