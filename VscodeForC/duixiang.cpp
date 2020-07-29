#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x=0;
    int a[2000000+5]={0};
    for (int i = 1; i < n+1; i++)
    {
        cin>>x;
        a[x]=1;
    }
    cin>>x;
    int sum=0;
    for (int i = 1; i <= x/2; i++)
    {
        if (a[i]==1&&a[x-i]==1&&x-i!=i)  //a[i]+a[j]=x
        {
            sum++;
        }
    }
    cout<<sum;
    return 0;
}