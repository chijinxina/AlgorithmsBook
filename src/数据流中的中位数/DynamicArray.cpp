//
// Created by chijinxin on 18-6-28.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 用大顶堆 + 小顶堆 来查找数据流中的中位数
 *
 * 用一个大顶堆实现左半边数据容器，则堆顶是最大元素
 * 用一个小顶堆实现右半边数据容器，则堆顶是最小元素
 * 向堆中插入数据的时间复杂度是O（log n）
 */

class DynamicArray{
public:
    void Insert(int num)
    {
        /*
         * 数据总和为偶数，新加入的元素进入小顶堆
         * （注意不是直接进入小顶堆，而是经过大顶堆筛选后的大顶堆中的最大元素进入小顶堆）
         */
        if( ((min_.size() + max_.size()) & 1) == 0 )
        {
            //新加入的元素首先进入大顶堆，由大顶堆筛选出最大元素加入到小顶堆中
            if(max_.size() > 0 && num < max_[0])
            {
                max_.push_back(num);
                push_heap(max_.begin(),max_.end(),less<int>());   //加入大顶堆
                num = max_[0];    //获取大顶堆 堆顶元素
                pop_heap(max_.begin(),max_.end(),less<int>());    //移动堆顶元素到尾部
                max_.pop_back();                                  //弹出大顶堆尾部元素
            }
            //将经过筛选的元素加入到小顶堆
            min_.push_back(num);
            push_heap(min_.begin(),min_.end(),greater<int>());
        }
        /*
         * 数据总和为奇数，新加入的元素进入大顶堆
         */
        else
        {
            //新加入的元素首先进入小顶堆，由小顶堆筛选出最小元素加入到大顶堆中
            if(min_.size()>0 && num > min_[0])
            {
                min_.push_back(num);
                push_heap(min_.begin(),min_.end(),greater<int>());   //将元素加入小顶堆
                num = min_[0];       //获取堆顶元素，最小元素
                pop_heap(min_.begin(),min_.end(),greater<int>());    //移动小顶堆对顶元素到尾部
                min_.pop_back();                                     //弹出小堆顶尾部元素
            }
            //将经过筛选的元素加入到大顶堆
            max_.push_back(num);
            push_heap(max_.begin(),max_.end(),less<int>());
        }
    }

    /*
     * 获取数据流中位数
     */
    double GetMedian()
    {
        cout<<"min size="<<min_.size()<<endl;
        cout<<"max size="<<max_.size()<<endl;
        if(min_.size()+max_.size()<=0)
        {
            cout<<"size < = 0!!!!";
            return 0;
        }
        //总数为偶数，取中间元素平均值
        if( ((min_.size()+max_.size()) & 1) ==0 )
        {
            return (double)(min_[0]+max_[0])/2;
        }
        else
        {
            return (double)min_[0];
        }
    }
private:
    vector<int> min_;
    vector<int> max_;
};

int main()
{
    int num;
    DynamicArray da;
    while(cin>>num)
    {
        da.Insert(num);
        cout<<"中位数："<<da.GetMedian()<<endl;
    }
    return 0;
}

