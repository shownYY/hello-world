#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char a[n+10][n+10];
    char b[n+10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i][n-1];
    }
     for (int i = 0; i < n; i++)
     {
         a[i][n-1] = a[i][0];
     }
     for (int i = 0; i < n; i++)
     {
         a[i][0] = b[i];
     }
     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             cout << a[i][j]<<" ";
         }
         cout<<endl;
   }
    return 0;
}