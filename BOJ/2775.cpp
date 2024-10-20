#include <iostream>
using namespace std;
int dp[15][15];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, k, n;
    for (int i = 1; i < 15; i++)
        dp[0][i] = i;
    for (int i = 1; i < 15; i++)
    {
        int sum = 0;
        for (int j = 1; j < 15; j++)
        {
            sum += dp[i - 1][j];
            dp[i][j] = sum;
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k >> n;
        cout << dp[k][n] << "\n";
    }
    return 0;
}