#include <iostream>
#include <algorithm>
using namespace std;
long long f[100] = {0};
int main()
{
    int a, n, m, x, k;
    cin >> a >> n >> m >> x;
    f[1] = f[2] = 1LL;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 2] + f[i - 1];
    k = (m - (f[n - 1 - 2] + 1) * a) / (f[n - 1 - 1] - 1);
    if ((m - (f[n - 1 - 2] + 1) * a) % (f[n - 1 - 1] - 1))
        cout << "No answer.\n";
    else if (x <= 2)
        cout << a << endl;
    else
        cout << (f[x - 2] + 1) * a + (f[x - 1] - 1) * k << endl;
    return 0;
}