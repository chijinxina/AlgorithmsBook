//
// Created by chijinxin on 18-8-5.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
 * 求两个有序数组元素两两相加的最小的K个和
 *
 * 用小顶堆实现
 * 思路： 首先将a[0]+b[0]的结果放到小顶堆中，此时堆中只有一个元素，自然满足小顶堆的条件，然后开始出堆操作，从堆中
 * 取出堆顶元素（也就是和最小的值），例如是：a[i]+b[j]，则需要向小顶堆中压入a[i+1]+b[j]和a[i]+b[j+1],当然还要
 * 保证数组下标不越界，如果下标越界则忽略，另外要保证已经压入到堆中的组合不再被压入堆中，不断进行出堆和入堆操作，
 * 重复K次，就得到了K个最小的组合值
 *
 * 堆的最大深度为logK,所以时间复杂度为O(K*logK)。
 */

struct Node{
    int i;
    int j;
    int sum;
    Node(int ii, int jj, int s):i(ii),j(jj),sum(s){}
    bool operator > (const Node &n) const
    {
        if(sum > n.sum) return true;
        else return false;
    }
};


vector<int> topKOfTwoSortedArray(const vector<int> &A, const vector<int> &B, int k)
{
    vector<int> result;
    if((A.size()==0 && B.size()==0) || k<=0) return result;
    int na = A.size();  int nb= B.size();
    if(k > na*nb) k = na*nb;
    map<pair<int,int>, bool> status;
    vector<Node> Heap;
    Heap.push_back(Node(0,0,A[0]+B[0]));  //将第一个元素插入到堆中
    status[make_pair(0,0)] = true;
    //make_heap默认是大顶堆(less<T>()) 小顶堆：greater<T>()
    make_heap(Heap.begin(), Heap.end(),greater<Node>());  //构建小顶堆

    while(k>0)
    {
        pop_heap(Heap.begin(),Heap.end(),greater<Node>());  //出堆操作
        Node temp = Heap.back();  //堆顶元素(被移动到了堆尾）
        Heap.pop_back();          //删除堆尾元素
        result.push_back(temp.sum);   //最小的第一个组合数的和
        --k;
        if(temp.i+1 < na && !status[make_pair(temp.i+1,temp.j)])
        {
            status[make_pair(temp.i+1,temp.j)] = true;  //标记已经访问过
            Heap.emplace_back(temp.i+1,temp.j,A[temp.i+1]+B[temp.j]);
            push_heap(Heap.begin(),Heap.end(),greater<Node>());   //入堆 小顶堆
        }
        if(temp.j+1 < nb && !status[make_pair(temp.i,temp.j+1)])
        {
            status[make_pair(temp.i,temp.j+1)] = true;  //标记已经访问过
            Heap.emplace_back(temp.i,temp.j+1,A[temp.i]+B[temp.j+1]);
            push_heap(Heap.begin(),Heap.end(),greater<Node>());   //入堆 小顶堆
        }
    }
    return result;
}


int main()
{
    vector<int> A = {1,2,3,4};
    vector<int> B = {2,3,4,5};
    int k = 12;

    vector<int> ans = topKOfTwoSortedArray(A, B, k);

    for (int i = 0; i < k; ++i){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
