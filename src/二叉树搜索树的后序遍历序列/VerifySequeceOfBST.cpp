//
// Created by chijinxin on 18-8-13.
//
#include <iostream>
#include <vector>
using namespace std;
/*
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果
 * BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），
 * 如果去掉最后一个元素的序列为T，那么T满足：T可以分成两段，前一段（左子树）小于x，
 * 后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。完美的递归定义
 */
bool verifySquenceOfBST(vector<int> &seq, int left, int right)
{
    if(left >= right) return true;

    int i = right;

    //从右到左找到小于根元素的元素下标
    while(left < i && seq[i-1] > seq[right]) --i;

    //判断剩下的元素是否满足小于根元素的条件

    for(int j=i-1; j >= left; --j)
    {
        if(seq[j] > seq[right]) return false;
    }
    return verifySquenceOfBST(seq, left, i-1) && verifySquenceOfBST(seq, i, right-1);
}

int main()
{
    vector<int> seq = {4,8,6,12,16,14,10};
    cout<<verifySquenceOfBST(seq,0,seq.size()-1)<<endl;
    return 0;
}
