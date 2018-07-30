//
// Created by chijinxin on 18-7-30.
//
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


int Partition(vector<int> &vec, int start, int end)
{
    int pivot = vec[start];
    while(start < end)
    {
        while(start < end && pivot <= vec[end] ) end--;
        vec[start] = vec[end];
        while(start < end && pivot >= vec[start]) start++;
        vec[end] = vec[start];
    }
    vec[start] = pivot;
    return start;
}

void QSort_Partition(vector<int> &vec, int start, int end)
{
    if(start >= end) return;
    int mid = Partition(vec,start,end);
    QSort_Partition(vec,start,mid-1);
    QSort_Partition(vec,mid+1,end);
}

/*
 * 非递归快排(使用栈实现)
 */
void QSort_stack(vector<int> &vec, int start, int end)
{
    stack<int> st;
    if(start < end)
    {
        int mid = Partition(vec,start,end);
        if(start < mid-1)
        {
            st.push(start);
            st.push(mid-1);
        }
        if(mid+1 < end)
        {
            st.push(mid+1);
            st.push(end);
        }
        //用栈保存每一个待排序的子串的首尾元素下标，在下一次white循环时取出这个范围，对这个范围内的子序列进行partition操作
        while(!st.empty())
        {
            int right = st.top();  //后进先出
            st.pop();
            int left = st.top();    //后进先出
            st.pop();
            mid = Partition(vec,left,right);
            if(left < mid-1)
            {
                st.push(left);
                st.push(mid-1);
            }
            if(mid+1 < right)
            {
                st.push(mid+1);
                st.push(right);
            }
        }
    }
}


int main()
{
    vector<int> vec = {10,23,8,1,2,3,5,4,6,2};
    QSort_stack(vec,0,vec.size()-1);
    for(int &x : vec)
    {
        cout<<x<<" ";
    }

}
