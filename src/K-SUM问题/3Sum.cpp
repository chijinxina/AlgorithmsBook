//
// Created by chijinxin on 18-7-16.
//
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
/*
 * 3Sum问题
 * https://leetcode.com/problems/3sum/
 * 思路：
 * 先将数组排序，然后从头开始依次挑选出第一个元素，在其后选两个元素（首尾指针法）
 */

vector<vector<int>> threesum(vector<int> &nums, int target)
{
    int len = nums.size();
    vector<vector<int>> result;
    vector<int> res;
    if(len<3) return result;

    multimap<int,int> mp;

    for(int i=0; i<len; i++)
    {
        mp.insert(make_pair(nums[i],i+1));
    }
    multimap<int,int>::iterator index = mp.begin();
    multimap<int,int>::iterator start = mp.begin();
    multimap<int,int>::iterator end = mp.begin();
    for(index=mp.begin(); index!= prev(mp.end(),2); ++index)   //倒数第二个
    {
        start = next(index,1);
        end = prev(mp.end(),1);
        while(start!=end)
        {
            if(index->first + start->first + end->first == target)
            {
                res.clear();
                res.push_back(index->second);
                res.push_back(start->second);
                res.push_back(end->second);
                sort(res.begin(),res.end());
                result.push_back(res);
                break;
            }
            else if(index->first + start->first + end->first < target)
            {
                start ++;
            }
            else
            {
                end--;
            }
        }
    }
    return result;
}



int main()
{
    vector<int> nums = {-2,-1,1,1,2};
    vector<vector<int>> res = threesum(nums,2);
    for_each(res.begin(),res.end(),
             [](vector<int> x)
             {
                 for_each(x.begin(),x.end(),
                          [](int xx)
                          {
                              cout<<xx<<" ";
                          });
                 cout<<endl;
             });
    return 0;
}
