#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, z, N = 1, K = 1;
    cin >> n >> k;
    for (int i = n; i > n - k; i--)
    {
        N *= i;
    }
    for (int i = 1; i <= k; i++)
    {
        K *= i;
    }
    z = N / K;
    cout << z;
    return 0;
}