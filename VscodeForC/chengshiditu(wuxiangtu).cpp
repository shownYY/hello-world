#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#define INF 999999
using namespace std;
int book[101], e[101][101];
int n;
int resmin = 9999999;
int path[100]; /// 用来保存路径
void dfs(int cur, int dis)
{
    int i;
    if (n == cur) //判断是否到达了目标城市
    {
        for (i = 1; i <= n; i++) /// 输出所有可能的路径
        {
            if (path[i])
            {
                cout<<path[i]<<" "; //输出路径
            }
        }
        cout<<"该路径对应的长度是:"<< dis<<endl; //输出对应路径长度
        if (resmin > dis)                               //更新最小路径
        {
            resmin = dis;
        }
        return;
    }
    for (i = cur; i <= n; ++i) //从1号城市到n号城市依次尝试
    {
        //判断当前城市cur到城市i是否有路，并判断城市i是否在已走过的路径中
        if (e[cur][i] != INF && book[i] == 0)
        {
            book[i] = 1; //标记城市i已经在路径中
            path[i] = i; //保存路劲到path数组中
            dfs(i, dis + e[cur][i]);
            book[i] = 0; /// 之前一部探索完毕后,取消对城市 i 的标记以便另一条路径选择顶点
            path[i] = 0;
        }
    }
}
int main()
{
    int i, j, a, b, c, m;
    cin>>n>>m;
    //初始化二维矩阵
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= n; ++j)
        {
            if (i == j)
            {
                e[i][j] = 0;
            }
            else
            {
                e[i][j] = INF;
            }
        }
    }

    //读入城市之间的道路
    for (i = 1; i <= m; ++i)
    {
        cin>>a>>b>>c;
        e[a][b] = c;
        e[b][a] = c;
    }
    book[1] = 1; //标记1号城市已经在路径中
    path[1] = 1;
    dfs(1, 0); //1表示当前所在城市标号，0表示当前已经走过的路程
    cout<<"最短路径的长度是："<<endl;
    cout<<resmin<<endl;; //打印最短路径
    return 0;
}

/*
cin:
5 8
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3
cout:
7
*/
