#include <bits/stdc++.h>
using namespace std;
//递归解斐波那契数列
//时间复杂度O(2^n)  指数级
int sum=0;
int F(int n)
{
    sum++;//用来统计递归次数
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
         return F(n - 1) + F(n - 2); 
    }
}
int main()
{
    cout << F(25);//计算斐波那契数列的第25项
    cout<<endl;
    cout<<"sum="<<sum<<endl;//重复计算次数
    return 0;
}