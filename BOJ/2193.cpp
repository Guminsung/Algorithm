#include <iostream>
using namespace std;
long long dp[2][90];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    dp[0][0] = 0;
    dp[1][0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
        dp[1][i] = dp[0][i - 1];
    }
    cout << dp[0][n - 1] + dp[1][n - 1];
    return 0;
}