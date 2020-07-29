#include <bits/stdc++.h>
using namespace std;
//递归解斐波那契数列  带备忘录的递归
//时间复杂度O(n)  线性
int a[1000];//备忘录数组
int sum=0;
int F(int n)
{
    sum++;//用来统计递归次数
    if (n == 1 || n == 2)
    {
        return 1;
    }
    if (a[n])
    {
        return a[n];
    }
    int V=F(n-1)+F(n-2);
    a[n]=V;//记录笔记
    return V;
}
int main()
{
    cout << F(25);//计算斐波那契数列的第25项
    cout<<endl;
    cout<<"sum="<<sum<<endl;//重复计算次数
    return 0;
}