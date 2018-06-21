//
// Created by chijinxin on 18-6-21.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
 * 实现并查集
 */
int pre[1000];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        pre[i] = i;
    }
}


int find(int x)
{
    int r = x;
    while(pre[r] != r)
    {
        r = pre[r];
    }
    //路径压缩
    int i=x, j;
    while(i != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
}

void join(int x, int y)
{
    int fx = pre[x];
    int fy = pre[y];
//    if(fx != fy)
//    {
        pre[fx] = fy;
 //   }
}

/*
 * 在并查集的基础上实现kruskal算法
 */

class edge{
public:
    int start;
    int end;
    int val;
};

int Kruskal(vector<edge> & d, int n)  //n为边的数量
{
    int sum = 0;

    //初始化
    init(n);

    //先将边集按权重从小到大排序
    sort(d.begin(),d.end(),
         [](const edge &e1, const edge &e2)
         {
             if(e1.val < e2.val)
                 return true;
             else
                 return false;
         });

    //从权最小的边开始加进图中
    for(int i=0;i<d.size();i++)
    {
        if(find(d[i].start) != find(d[i].end))
        {
            sum += d[i].val;
            join(d[i].start, d[i].end);
        }
    }
    return sum;

}

int main()
{
    vector<edge> dd;
    edge t1;
    t1.start=2;
    t1.end  =4;
    t1.val  =1;
    dd.push_back(t1);
    t1.start=1;
    t1.end  =2;
    t1.val  =2;
    dd.push_back(t1);
    t1.start=2;
    t1.end  =3;
    t1.val  =1;
    dd.push_back(t1);
    t1.start=1;
    t1.end  =3;
    t1.val  =2;
    dd.push_back(t1);
    cout<<Kruskal(dd,4)<<endl;
    return 0;
}
