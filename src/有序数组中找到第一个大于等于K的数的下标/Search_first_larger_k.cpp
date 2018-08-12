//
// Created by chijinxin on 18-8-11.
//
#include <iostream>
#include <vector>

using namespace std;

int search_first_larger_k(vector<int> &vec, int k)
{
    if(vec.size()==0 || vec.back()<k ) return -1;

    int len = vec.size();
    int result = -1;
    int right = len - 1;
    int left = 0;

    while(left <= right)
    {
        int mid = left + (right - left)/2;

        if( vec[mid] >= k )
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return result;
}

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,10};
    cout<<search_first_larger_k(vec, 10)<<endl;
    return 0;
}
