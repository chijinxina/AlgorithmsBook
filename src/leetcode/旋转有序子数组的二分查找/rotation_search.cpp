//
// Created by chijinxin on 18-9-12.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 * 旋转数组的二分查找
 */
int search(const vector<int> &nums, int target)
{
    int first = 0, last = nums.size()-1;

    while(first != last)
    {
        int mid = first + (last-first)/2;

        if(nums[mid] == target)
        {
            return mid;
        }
        //mid 位于左半部
        if(nums[first] <= nums[mid])
        {
            if(nums[first] <= target && target < nums[mid])
            {
                last = mid - 1;
            }
            else first = mid + 1;
        }
        //mid 位于右半部
        else
        {
            if(nums[mid] < target && target <= nums[last-1])
            {
                first = mid + 1;
            }
            else last = mid - 1;
        }
    }
}

/*
 * 旋转数组查找最小值
 * 特例： 一旦发现数组中第一个数字小于最后一个数字，表明数组的排序的，就可以直接返回第一个数字了
 */
int MinSearch(vector<int> &nums)
{
    int first = 0;
    int last = nums.size()-1;
    int mid = 0;
    while(nums[first] >= nums[last])
    {
        //前后相差1 结束
        if(last - first == 1)
        {
            mid = last;
            break;
        }
        mid = first + (last - first)/2;
        if(nums[mid] >= nums[first])
        {
            first = mid;
        }
        else if(nums[mid] <= nums[last])
        {
            last = mid;
        }
    }
    return nums[mid];
}

void fibr(vector<int> &data)
{
    int tmp1 = data[0];
    int tmp2 = data[1];
    int tmp;
    int i = 2;
    while(i<data.size())
    {
        tmp = tmp1 + tmp2;
        tmp1 = tmp2;
        tmp2 = data[i];
        data[i] = tmp;
        ++i;
    }
}

int main()
{
    vector<int> vec{4,5,6,7,0,1,2}; //0,1,2,4,5,6,7
    cout<<search(vec,0)<<endl;
    cout<<MinSearch(vec)<<endl;
    vector<int> data{0,1,2,3,4,5,6,7,8};
    fibr(data);
    cout<<endl;
    return 0;
}