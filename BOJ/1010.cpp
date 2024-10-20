#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, z;
    long long N, M;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n >> m;
        if (m - n < n)
            n = m - n;
        N = 1;
        M = 1;
        for (int i = m; i > m - n; i--)
        {
            M *= i;
        }
        for (int i = 1; i <= n; i++)
        {
            N *= i;
        }
        z = M / N;
        cout << z << "\n";
    }
    return 0;
}