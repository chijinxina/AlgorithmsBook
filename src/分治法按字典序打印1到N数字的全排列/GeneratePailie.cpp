//
// Created by chijinxin on 18-8-6.
//
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 将数字 1 - N 进行全排列 按字典序从小到大排列
 * 全排列每个元素， 首先选择一个元素出来，放在一个排列的最前面， 把剩下的元素当成一个新的问题进行全排列操作
 * 在新的元素集合中再次选择一个元素，放在排列的第二个位置，剩下的元素又是一个新的集合，依次执行同样的操作，
 * 直到剩余集合为空，一条排列完成
 */
int array[10]={1,2,3,4,5,6,7,8,9};

void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/*
 * 递归法输出全排列
 */
void recurPermutation(int *arr, int n, int i)
{
    if(i==n-1) {
        printArray(arr, n);
    }
    for(int j=i; j<n; j++)
    {
        swap(arr[i], arr[j]);
        recurPermutation(arr, n, i+1);
        swap(arr[i], arr[j]);
    }
}

/*
 * 按字典序输出全排列
 */
void permutation(int *arr, int n)
{
    int i, j, k;
    int count = 1;
    printArray(arr, n);
    while(true)
    {
        i=n-1;
        while(i>0 && arr[i-1] > arr[i]) i--;

        if (i==0) break;

        for(j=i, k=n-1; j<k; j++, k--)
        {
            swap(arr[j], arr[k]);
        }

        for(j=i; j<n; j++)
        {
            if(arr[j] > arr[i-1])
                break;
        }

        swap(arr[i-1], arr[j]);
        count++;
        printArray(arr, n);
    }
    printf("Total permutations: %d\n", count);
}


int main()
{
    //recurPermutation(array,3,0);
    permutation(array,4);

    return 0;
}
