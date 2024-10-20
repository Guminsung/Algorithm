#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> p(20001);
priority_queue<pair<int, int>> q;
int weight[20001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, u, v, w;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        p[u].push_back(make_pair(v, w));
    }
    for (int i = 1; i <= n; i++)
        weight[i] = 3000001;
    q.push(make_pair(0, k));
    weight[k] = 0;
    while (!q.empty())
    {
        int cost = -q.top().first, temp = q.top().second;
        q.pop();
        for (int i = 0; i < p[temp].size(); i++)
            if (weight[p[temp][i].first] > cost + p[temp][i].second)
            {
                weight[p[temp][i].first] = cost + p[temp][i].second;
                q.push(make_pair(-weight[p[temp][i].first], p[temp][i].first));
            }
    }
    for (int i = 1; i <= n; i++)
    {
        if (weight[i] == 3000001)
            cout << "INF\n";
        else
            cout << weight[i] << "\n";
    }
    return 0;
}