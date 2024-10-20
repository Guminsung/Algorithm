#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> p(1001);
queue<int> q;
bool visited[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, u, v, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (visited[i] == false)
        {
            q.push(i);
            visited[i] = true;
            cnt++;
            while (!q.empty())
            {
                int temp = q.front();
                q.pop();
                for (int j = 0; j < p[temp].size(); j++)
                    if (visited[p[temp][j]] == false)
                    {
                        visited[p[temp][j]] = true;
                        q.push(p[temp][j]);
                    }
            }
        }
    cout << cnt;
    return 0;
}