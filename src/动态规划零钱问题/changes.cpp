//
// Created by chijinxin on 18-7-18.
//
#include <iostream>
#include <vector>

using namespace std;
/*
 * 零钱问题 dp
 * 有一个数组changes,changes中所有的值为正数且不重复，每个值代表一种面值的货币，每种面值可以使用多次，对于一个给定值x，计算组成这个值的方案数
 *
 * f[i][j]表示零钱i使用changes[j]的方案数（这里changes从1开始才是真正的钱数）
 * 初始态：
 *      f[0][0]=1
 *      f[0][j]=1 钱数为0 则方案数就一种，就是全取0
 *      f[i][0]=0  不取钱，方案数为0
 *  递推公式：
 *      f[i][j] = f[i][j-1] + f[i-changes[j-1]][j]
 *      f[i][j-1]表示不取changes[j-1]这种面值的钱 有f[i][j-1]能凑成i
 *      f[i-changes[j-1][j]表示使用了changes[j-1]这种面值的钱
 */

int countWays(vector<int> &changes, int x)
{
    vector<vector<int>> f(x+1,vector<int>(changes.size()+1));
    //初始条件
    f[0][0] = 1;
    for(int i=0;i<x+1;i++)
    {
        f[i][0] = 0;
    }
    for(int j=0;j<f[0].size();j++)
    {
        f[0][j] = 1;
    }

    for(int i=1;i<x+1;i++)
    {
        for(int j=1;j<=changes.size();j++)
        {
            //合法性检查
            int tmp = i - changes[j-1];
            if(tmp>=0 && tmp<=x)
            {
                f[i][j] = f[i][j-1] + f[tmp][j];
            }
            else
            {
                f[i][j] = f[i][j-1];
            }
        }
    }
    return f[x][changes.size()];
}

int main()
{
    vector<int> changes ={1,2,3,4,5,6,7};
    cout<<countWays(changes,3);
    return 0;
}
