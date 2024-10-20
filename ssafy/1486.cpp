#include <iostream>
using namespace std;
bool dp[21][200001];
int v[21];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, b, num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int sum = 0;
        cin >> n >> b;
        for (int j = 1; j <= n; j++)
        {
            cin >> num;
            v[j] = num;
            sum += num;
        }
        dp[0][sum] = true;
        for (int j = 1; j <= n; j++)
            for (int k = sum; k >= 1; k--)
                if (dp[j - 1][k] == true)
                {
                    dp[j][k] = true;
                    if (k - v[j] > 0)
                        dp[j][k - v[j]] = true;
                }
        for (int j = b; j <= sum; j++)
            if (dp[n][j] == true)
            {
                cout << "#" << i + 1 << " " << j - b << "\n";
                break;
            }
        for (int j = 0; j <= n; j++)
        {
            v[j] = 0;
            for (int k = sum; k >= 1; k--)
                dp[j][k] = false;
        }
    }
    return 0;
}