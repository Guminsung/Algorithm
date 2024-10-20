#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
bool visited[100001];
int a[100001];
int cnt = 1;
queue<int> q;
vector<vector<int>> p(100001);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, r, u, v, num;
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        p[u].push_back(v);
        p[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(p[i].begin(), p[i].end());
    q.push(r);
    visited[r] = true;
    while (q.size() > 0)
    {
        num = q.front();
        a[num] = cnt++;
        q.pop();
        for (int i = 0; i < p[num].size(); i++)
        {
            if (visited[p[num][i]] == false)
            {
                visited[p[num][i]] = true;
                q.push(p[num][i]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << "\n";
    return 0;
}