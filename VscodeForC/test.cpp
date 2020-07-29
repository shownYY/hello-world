#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char a[n][n];
    char b[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        b[i] = a[0][i];
    }
    for (int i = 0; i < n; i++)
    {
        a[n][i] = a[0][i];
    }
    for (int i = 0; i < n; i++)
    {
        a[n][i] = b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}