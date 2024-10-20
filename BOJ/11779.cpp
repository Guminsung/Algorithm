#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int>>> v(1001);
priority_queue<pair<int, int>> q;
pair<int, int> visited[1001];
int pos[1001];
int INF = 999999999;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b, cost, s, e;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        visited[i].first = INF;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> cost;
        v[a].push_back(make_pair(b, cost));
    }
    cin >> s >> e;
    visited[s].first = 0;
    q.push(make_pair(0, s));
    while (q.top().second != e)
    {
        int w = -q.top().first, p = q.top().second;
        q.pop();
        for (int i = 0; i < v[p].size(); i++)
            if (visited[v[p][i].first].first > v[p][i].second + visited[p].first)
            {
                visited[v[p][i].first].first = v[p][i].second + visited[p].first;
                visited[v[p][i].first].second = p;
                q.push(make_pair(-visited[v[p][i].first].first, v[p][i].first));
            }
    }
    cout << visited[e].first << "\n";
    int temp = e, cnt = 0;
    while (temp != 0)
    {
        pos[cnt++] = temp;
        temp = visited[temp].second;
    }
    cout << cnt << "\n";
    for (int i = cnt - 1; i >= 0; i--)
        cout << pos[i] << " ";
    return 0;
}