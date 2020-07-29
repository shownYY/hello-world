#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[100]={0};
    int b[100]={0};
    int c=0;

    cin >> c;
    for (int i = 0; i < c; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (a[i] > a[j - 1])
            {
                b[i]++;
            }
        }
    }

    for (int i = 0; i < c; i++)
    {
        cout << b[i]<<" ";
    }
}