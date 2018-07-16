//
// Created by chijinxin on 18-7-16.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;
/*
 * 2Sum问题，主要解决方法有hashmap， 二分法思路，  前后指针思路
 * 2Sum https://leetcode.com/problems/two-sum/
 */

/*
 * 1. 采用hashmap方法，
 * O(n)
 */
vector<int> twoSum1(vector<int> &nums, int target)
{
    vector<int> res;
    unordered_map<int,int> mp;
    int len = nums.size();

    for(int i=0;i<len;i++)
    {
        if(mp.find(target-nums[i]) != mp.end())  //找到了
        {
            res.push_back(mp[target-nums[i]]);
            res.push_back(i+1);
        }
        else //找不到
        {
            mp.insert(make_pair(nums[i],i+1));
        }
    }
    return res;

}
/*
 * 2. 排序+二分搜索
 * O(nlogn)
 */
int bsearch(vector<int> &nums, int left, int right, int key)
{
    while(left<=right)
    {
        int mid = left + (right-left)>>2;
        if(nums[mid]<key)
        {
            left = mid + 1;
        }
        else if(nums[mid]>key)
        {
            right = mid - 1;
        }
        else
        {
            return mid;
        }

    }
    return -1;
}


/*
 * 排序 + 前后两个指针
 * O(nlogn)
 */

vector<int> twosum2(vector<int> &nums, int target)
{
    vector<int> res;
    int len = nums.size();

    if(len<2) return res;

    multimap<int,int> mp;
    for(int i=0;i<len;i++)
    {
        mp.insert(make_pair(nums[i],i));
    }
    //sort(nums.begin(),nums.end());
    //首尾指针法
    multimap<int,int>::iterator start = mp.begin();
    multimap<int,int>::iterator end = --mp.end();
//    int start = 0;
//    int end = len - 1;
    while(start != end)
    {
        if(start->first + end->first == target)
        {
            res.push_back(start->second);
            res.push_back(end->second);
            sort(res.begin(),res.end());
            break;
        }
        else if(start->first + end->first < target)
        {
            start++;
        }
        else
        {
            end--;
        }
    }
    return res;
}

int main()
{
    vector<int> data = {3,2,4};
    vector<int> res = twosum2(data,6);
    for_each(res.begin(),res.end(),
             [](int x)
             {
                 cout<<x<<" ";
             });
    return 0;
}