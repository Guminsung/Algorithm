#include <iostream>
using namespace std;
int dp[401][401];
int INF = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, v, e, num, min = INF;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                dp[i][j] = 0;
            else
                dp[i][j] = INF;
    for (int i = 0; i < m; i++)
    {
        cin >> v >> e >> num;
        dp[v][e] = num;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dp[i][j] > dp[i][k] + dp[k][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (min > dp[i][j] + dp[j][i])
                min = dp[i][j] + dp[j][i];
    if (min == INF)
        cout << -1;
    else
        cout << min;
    return 0;
}