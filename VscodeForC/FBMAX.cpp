#include <bits/stdc++.h>
using namespace std;
//解斐波那契数列
//时间复杂度O(1)
int sum = 0;
int F(int n)
{
    sum++;
    if (n <= 2)
    {
        return 1;
    }
    int n1 = 1, n2 = 1, n3;
    for (int i = 3; i < n + 1; i++)
    {
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
    }
    return n3;
}
int main()
{
    cout << F(25) << endl;
    cout << "sum=" << sum;
    return 0;
}