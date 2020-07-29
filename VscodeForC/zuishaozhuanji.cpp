#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define INF 999999
//最少转机
struct note
{
    int x; // 城市编号
    int s; // 转机次数
};
int book[100];
int main()
{
    int i, j, m, n, cur;
    int a, b, e[101][101];
    int head, tail;
    int start, end;
    int flag = 0;
    struct note que[2501];
    cin >> n >> m >> start >> end;
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

    //读入城市之间的航班
    for (i = 1; i <= m; ++i)
    {
        cin >> a >> b;
        //注意这里是无向图
        e[a][b] = 1;
        e[b][a] = 1;
    }
    //队列初始化
    head = 1;
    tail = 1;
    //从start号城市出发，将start号城市加入队列
    que[tail].x = start;
    que[tail].s = 0;
    tail++;
    book[start] = 1; //标记start号城市已经在队列中
    //当队列不为空时循环
    while (head < tail)
    {
        cur = que[head].x;       //当前队列中首城市的编号
        for (i = 1; i <= n; ++i) //从1到n依次尝试
        {
            //从城市cur到城市i是否有航班且判断城市i是否在队列中
            if (e[cur][i] == 1 && book[i] == 0)
            {
                //不在队列中，入队
                que[tail].x = i;
                que[tail].s = que[head].s + 1; //转机次数加1
                tail++;
                //标记城市i已经在队列中
                book[i] = 1;
            }

            if (que[tail - 1].x == end) //达到目标城市, 退出循环
            {
                flag = 1;
                break;
            }
        }

        if (flag == 1)
        {
            break;
        }

        head++; //有head++，才能继续扩展
    }

    //打印队列中末尾最后一个（目标城市）的转机次数
    //注意tail是指向队列队尾的下一个位置，所以这里需要减1
    cout << "从" << start << "城市转机到" << end << "城市的最少转机次数是：";
    cout << que[tail - 1].s << endl;
    return 0;
}
/*
输入
5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
输出
2
*/