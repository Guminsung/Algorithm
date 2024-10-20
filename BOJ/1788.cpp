#include <iostream>
using namespace std;
int m = 1000000;
int Abs = 1000000000;
int dp[2000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    dp[m] = 0;
    dp[m + 1] = 1;
    cin >> n;
    if (n >= 0)
        for (int i = 2; i <= n; i++)
            dp[m + i] = (dp[m + i - 1] + dp[m + i - 2]) % Abs;
    else
        for (int i = -1; i >= n; i--)
        {
            dp[m + i] = dp[m + i + 2] - dp[m + i + 1];
            if (dp[m + i] >= 0)
                dp[m + i] %= Abs;
            else
            {
                int temp = -dp[m + i];
                temp %= Abs;
                dp[m + i] = -temp;
            }
        }
    if (dp[m + n] > 0)
        cout << 1 << "\n"
             << dp[m + n];
    else if (dp[m + n] < 0)
        cout << -1 << "\n"
             << -dp[m + n];
    else
        cout << 0 << "\n"
             << dp[m + n];
    return 0;
}