#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(int n);
bool visited[100001];
int a[100001];
int cnt = 1;
vector<vector<int>> p(100001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, r, u, v;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(p[i].begin(), p[i].end(), greater<int>());
    dfs(r);
    for (int i = 1; i <= n; i++)
        cout << a[i] << "\n";
    return 0;
}

void dfs(int n)
{
    if (visited[n] == false)
    {
        visited[n] = true;
        a[n] = cnt++;
        for (int i = 0; i < p[n].size(); i++)
            dfs(p[n][i]);
    }
}