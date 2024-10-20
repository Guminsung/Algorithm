#include <iostream>
using namespace std;
int dp[101][101];
int INF = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x, y, num;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> num;
        if (dp[x][y] > num)
            dp[x][y] = num;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[i][j] == INF)
                cout << 0 << " ";
            else
                cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}