#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
void dfs(int x);
void bfs(int x);
vector<int> v[1001];
bool visited[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, start, a, b;
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end());
    dfs(start);
    cout << "\n";
    for (int i = 1; i <= 1000; i++)
        visited[i] = false;
    bfs(start);
    return 0;
}

void dfs(int x)
{
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < v[x].size(); i++)
        if (visited[v[x][i]] == false)
            dfs(v[x][i]);
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (q.size() > 0)
    {
        int node = q.front();
        cout << node << " ";
        q.pop();
        for (int i = 0; i < v[node].size(); i++)
            if (visited[v[node][i]] == false)
            {
                q.push(v[node][i]);
                visited[v[node][i]] = true;
            }
    }
}