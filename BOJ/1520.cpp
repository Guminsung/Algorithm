#include <iostream>
using namespace std;
int dfs(int a, int b, int m, int n);
int v[500][500];
int dp[500][500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n, num;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            v[i][j] = num;
        }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }
    cout << dfs(0, 0, m, n);
    return 0;
}

int dfs(int a, int b, int m, int n)
{
    if (a == m - 1 && b == n - 1)
        return 1;
    else if (dp[a][b] != -1)
        return dp[a][b];
    else
    {
        int sum = 0;
        if (a > 0 && v[a - 1][b] < v[a][b])
            sum += dfs(a - 1, b, m, n);
        if (b > 0 && v[a][b - 1] < v[a][b])
            sum += dfs(a, b - 1, m, n);
        if (a < m - 1 && v[a + 1][b] < v[a][b])
            sum += dfs(a + 1, b, m, n);
        if (b < n - 1 && v[a][b + 1] < v[a][b])
            sum += dfs(a, b + 1, m, n);
        dp[a][b] = sum;
        return sum;
    }
}