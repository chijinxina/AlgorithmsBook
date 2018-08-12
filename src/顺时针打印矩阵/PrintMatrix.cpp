//
// Created by chijinxin on 18-8-11.
//
#include <iostream>
#include <vector>
using namespace std;

/*
 * 顺时针打印矩阵
 */
vector<int> printMatrix(vector<vector<int> > matrix) {
    int n1=0,m1=0;
    int m2 = matrix.size()-1;
    int n2 = matrix[0].size()-1;
    vector<int> result;
    while(n1<=n2 && m1<=m2)
    {
        if(m1<=m2)
        for(int i=n1;i<=n2;i++) result.push_back(matrix[m1][i]);
        m1++;
        if(n1<=n2)
        for(int i=m1;i<=m2;i++) result.push_back(matrix[i][n2]);
        n2--;
        if(m1<=m2)
        for(int i=n2;i>=n1;i--) result.push_back(matrix[m2][i]);
        m2--;
        if(n1<=n2)
        for(int i=m2;i>=m1;i--) result.push_back(matrix[i][n1]);
        n1++;
    }
    return result;
}


int main()
{
    vector<vector<int>> matrix;
    vector<int> a1 = {1};
    vector<int> a2 = {2};
    vector<int> a3 = {3};
    vector<int> a4 = {4};
    vector<int> a5 = {5};
    matrix.push_back(a1);matrix.push_back(a2);matrix.push_back(a3);matrix.push_back(a4);matrix.push_back(a5);
    vector<int> result = printMatrix(matrix);
    return 0;
}
