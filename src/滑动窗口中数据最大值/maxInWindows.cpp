//
// Created by chijinxin on 18-8-13.
//
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
/*
 * 给定一个数组 和 滑动窗口的大小 找出滑动窗口中数组的最大值
 *
 * 思路：滑动窗口应当是队列，但为了得到滑动窗口的最大值，队列序可以从两端删除元素，因此使用双端队列。
 *     原则：
 *     对新来的元素k，将其与双端队列中的元素相比较
 *     1）前面比k小的，直接移出队列（因为不再可能成为后面滑动窗口的最大值了!）,
 *     2）前面比k大的X，比较两者下标，判断X是否已不在窗口之内，不在了，直接移出队列
 *     队列的第一个元素是滑动窗口中的最大值
 */
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    vector<int> result;
    if(num.size() >= size && size >= 1)
    {
        deque<int> index;
        for(int i=0; i<size; ++i)
        {
            //将双端队列中 比当前值小的元素全部出队
            while (!index.empty() && num[i]>=num[index.back()])
            {
                index.pop_back();
            }
            index.push_back(i);   //双端队列中保存的是数组元素的下标
        }
        //滑动窗口向前滑动
        for(int i=size; i<num.size(); ++i)
        {
            result.push_back(num[index.front()]);
            while (!index.empty() && num[i] >= num[index.back()])
            {
                index.pop_back();
            }
            if(!index.empty() && i - index.front() >= size)
            {
                index.pop_front();
            }
            index.push_back(i);
        }
        result.push_back(num[index.front()]);
    }
    return result;
}


int main()
{
    vector<int> vec{1,2,3,3,2,5,7,3,2,8,9,1};
    maxInWindows(vec,3);
    return 0;
}
