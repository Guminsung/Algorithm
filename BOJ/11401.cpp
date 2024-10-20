#include <iostream>
using namespace std;
void DC(long long DOWN, int k);
int MOD = 1000000007;
long long f_DOWN = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    long long UP = 1, DOWN = 1, result = 1;
    cin >> n >> k;
    for (int i = n; i > n - k; i--)
    {
        UP *= i;
        UP %= MOD;
    }
    for (int i = 1; i <= k; i++)
    {
        DOWN *= i;
        DOWN %= MOD;
    }
    k = MOD - 2;
    DC(DOWN, k);
    result = (UP * f_DOWN) % MOD;
    cout << result;
    return 0;
}

void DC(long long DOWN, int k)
{
    if (k > 0)
    {
        long long mul = DOWN % MOD;
        if (k % 2 == 1)
        {
            f_DOWN *= mul;
            f_DOWN %= MOD;
        }
        DC(mul * mul, k / 2);
    }
}