//
// Created by chijinxin on 18-4-7.
//
#include <iostream>
#include <algorithm>

using namespace std;


int a[10] = {2,8,1,4,3,5,10,9,6,7};

void adjustHeap(int a[], int n, int i)
{
    int temp = a[i];  //先取出当前第i个元素
    for(int k=2*i+1; k<n; k=2*k+1)  //从i节点第一个左子树节点
    {
        if(a[k]<a[k+1] && k+1<n) //如果右节点存在且大于左节点 则 k 指向右节点
        {
            k++;
        }
        if(a[k] > temp)  //左右孩子节点数值大于父节点的数值 ： 将左右孩子节点中数值大的赋值给父节点（不用交换）
        {
            a[i] = a[k];
            i = k; //接着往下面的节点开始调整
        }
        else
        {
            break;
        }
    }

    //最后将temp的值放在最终的位置
    a[i] = temp;

}

void HeadSort(int a[], int n)
{
    //1. 从下到上 从右到左 依次调整大顶堆 （构建大顶堆）
    for(int i=n/2-1;i>=0;i--)
        adjustHeap(a,n,i);
    //2. 交换堆顶元素和数组末尾元素
    for(int j=n-1;j>0;j--)
    {
        a[0] ^= a[j];
        a[j] ^= a[0];
        a[0] ^= a[j];
        adjustHeap(a,j,0); //重新对 j 个元素的堆进行调整 使其满足大顶堆定义
    }
}



int main()
{
    for_each(a,a+10,[](int x){cout<<x<<" ";});
    cout<<endl;
    HeadSort(a,10);
    for_each(a,a+10,[](int x){cout<<x<<" ";});
    return 0;
}
