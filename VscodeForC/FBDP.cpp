#include <bits/stdc++.h>
using namespace std;
int a[1000];
//动态规划解
//时间复杂度O(n)  线性
int sum = 0;
int F(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    a[1] = a[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        sum++;
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}
int main()
{
    cout << F(25);
    cout << "sum=" << sum;
    return 0;
}