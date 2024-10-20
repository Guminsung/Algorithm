#include <iostream>
using namespace std;
int dfs(int p1, int p2);
void route(int p1, int p2);
int dp[1001][1001];
pair<int, int> v[1001];
int n, w;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, y;
    cin >> n >> w;
    for (int i = 1; i <= w; i++)
    {
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }
    for (int i = 0; i <= 1000; i++)
        for (int j = 0; j <= 1000; j++)
            dp[i][j] = -1;
    cout << dfs(0, 0) << "\n";
    route(0, 0);
    return 0;
}

int dfs(int p1, int p2)
{
    if (p1 == w || p2 == w)
        return 0;
    if (dp[p1][p2] != -1)
        return dp[p1][p2];
    int nxt = max(p1, p2) + 1;
    int d1, d2;
    if (p1 == 0)
        d1 = abs(1 - v[nxt].first) + abs(1 - v[nxt].second);
    else
        d1 = abs(v[p1].first - v[nxt].first) + abs(v[p1].second - v[nxt].second);
    if (p2 == 0)
        d2 = abs(n - v[nxt].first) + abs(n - v[nxt].second);
    else
        d2 = abs(v[p2].first - v[nxt].first) + abs(v[p2].second - v[nxt].second);
    int fd1 = d1 + dfs(nxt, p2), fd2 = d2 + dfs(p1, nxt);
    dp[p1][p2] = min(fd1, fd2);
    return dp[p1][p2];
}

void route(int p1, int p2)
{
    if (p1 == w || p2 == w)
        return;
    int nxt = max(p1, p2) + 1;
    int d1, d2;
    if (p1 == 0)
        d1 = abs(1 - v[nxt].first) + abs(1 - v[nxt].second);
    else
        d1 = abs(v[p1].first - v[nxt].first) + abs(v[p1].second - v[nxt].second);
    if (p2 == 0)
        d2 = abs(n - v[nxt].first) + abs(n - v[nxt].second);
    else
        d2 = abs(v[p2].first - v[nxt].first) + abs(v[p2].second - v[nxt].second);
    if (dp[nxt][p2] + d1 < dp[p1][nxt] + d2)
    {
        cout << 1 << "\n";
        route(nxt, p2);
    }
    else
    {
        cout << 2 << "\n";
        route(p1, nxt);
    }
}