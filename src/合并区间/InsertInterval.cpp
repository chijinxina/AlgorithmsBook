//
// Created by chijinxin on 18-4-16.
//
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Intervals  //区间类
{
public:
    int start; //区间开始点
    int end;   //区间结束点
    Intervals(int x, int y):start(x),end(y){}
    bool operator< (const Intervals& t) const
    {
        if(start < t.start) return true;
        else if(start > t.start) return false;
        else return end < t.end?true:false;
    }
    friend ostream& operator<< (ostream &out, const Intervals &t);  //重载输出流
};
ostream& operator<< (ostream &out, const Intervals &t)
{
    out<<"["<<t.start<<","<<t.end<<"]";
    return out;
}


/*
 * 插入一个新区间到区间集合中区
 */
void InsertInterval(map<Intervals,int> &arr, Intervals tmp)
{
    if(arr.empty()) arr.insert(make_pair(tmp,1));
    else
    {
        map<Intervals,int>::iterator iter1,iter2; //iter1 前一个重合区间  iter2后一个重合区间
        int newStart=0,newEnd=0;

        for(iter1=arr.begin();iter1!=arr.end();++iter1)
        {
            if(tmp.start <= iter1->first.end && tmp.start>= iter1->first.start)
            {
                newStart = iter1->first.start;
                break;
            }
        }
        for(iter2=arr.begin();iter2!=arr.end();++iter2)
        {
            if( tmp.end >= iter2->first.start && tmp.end <=iter2->first.end)
            {
                newEnd = iter2->first.end;
                break;
            }
        }
        /*
         * 第一种情况 （* *）
         */
        if(iter1!=arr.end() && iter2!=arr.end())
        {
            ++iter2;
            do
            {
                iter1 = arr.erase(iter1);
            }
            while(iter1!=iter2);
            Intervals tt(newStart,newEnd);
            arr.insert(make_pair(tt,1));
        }
        else if (iter1==arr.end() && iter2!=arr.end())
        {
            arr.erase(iter2);
            Intervals tt(tmp.start,newEnd);
            arr.insert(make_pair(tt,1));
        }
        else if (iter2==arr.end() && iter1!=arr.end())
        {
            arr.erase(iter1);
            Intervals tt(newStart,tmp.end);
            arr.insert(make_pair(tt,1));
        }
        else
        {
            arr.insert(make_pair(tmp,1));
        }
    }
}



int main()
{
    map<Intervals,int> arr;
    Intervals t1(1,5);
    Intervals t2(6,10);
    Intervals t3(15,20);
    cout<<"Insert t1[1,5] :"<<endl;
    InsertInterval(arr,t1);
    for_each(arr.begin(),arr.end(),[](pair<Intervals,int> x){cout<<x.first<<" ";}); cout<<endl;

    cout<<"Insert t2[6,10] :"<<endl;
    InsertInterval(arr,t2);
    for_each(arr.begin(),arr.end(),[](pair<Intervals,int> x){cout<<x.first<<" ";}); cout<<endl;

    cout<<"Insert t3[15,20] :"<<endl;
    InsertInterval(arr,t3);
    for_each(arr.begin(),arr.end(),[](pair<Intervals,int> x){cout<<x.first<<" ";}); cout<<endl;

    cout<<"Insert t4[4,6] :"<<endl;
    Intervals t4(4,6);
    InsertInterval(arr,t4);
    for_each(arr.begin(),arr.end(),[](pair<Intervals,int> x){cout<<x.first<<" ";}); cout<<endl;

    cout<<"Insert t5[10,15] :"<<endl;
    Intervals t5(11,15);
    InsertInterval(arr,t5);
    for_each(arr.begin(),arr.end(),[](pair<Intervals,int> x){cout<<x.first<<" ";}); cout<<endl;

    cout<<"Insert t6[10,10] :"<<endl;
    Intervals t6(10,11);
    InsertInterval(arr,t6);
    for_each(arr.begin(),arr.end(),[](pair<Intervals,int> x){cout<<x.first<<" ";}); cout<<endl;


    return 0;
}
