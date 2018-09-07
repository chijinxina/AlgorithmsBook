//
// Created by chijinxin on 18-8-27.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
 * 打印矩阵从左上角到右下角所有的路径
 * 类似与二叉树从根节点到叶子节点所有的路径
 */
vector<int> x1 = {1,2,3};
vector<int> x2 = {4,5,6};
vector<vector<int>> matrix{x1,x2};


vector<int> res;

void printPath(vector<vector<int>> &matrix,vector<vector<int>> &result, int x, int y)
{
    int m = matrix.size();
    int n= matrix[0].size();

    //边界条件
    if(x>m-1 || y >n-1) return;

    //首先将元素保存到数组中
    res.push_back(matrix[x][y]);
    //递归下方元素
    printPath(matrix,result, x+1, y);

    //找到出口，保存路径
    if(x == m-1 && y == n-1)
    {
        result.push_back(res);
    }
    //递归右方元素
    printPath(matrix,result, x, y+1);

    //没有找到出口，将尾部元素删除
    res.pop_back();
}


int main()
{
    vector<vector<int>> result;
    printPath(matrix, result, 0 , 0);
    cout<<1<<endl;
    return 0;
}
