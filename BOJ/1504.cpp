#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void min_cost(int x, int n);
vector<vector<pair<int, int>>> p(20001);
priority_queue<pair<long long, int>> q;
long long weight[801];
int INF = 200000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b, u, v, w;
    long long suma = 0, sumb = 0, sum;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        p[u].push_back(make_pair(v, w));
        p[v].push_back(make_pair(u, w));
    }
    cin >> a >> b;
    min_cost(1, n);
    suma += weight[a];
    sumb += weight[b];
    min_cost(a, n);
    suma += weight[b];
    sumb += weight[n];
    min_cost(b, n);
    suma += weight[n];
    sumb += weight[a];
    if (suma > sumb)
        sum = sumb;
    else
        sum = suma;
    if (sum >= INF)
        cout << -1;
    else
        cout << sum;
    return 0;
}

void min_cost(int x, int n)
{
    for (int i = 1; i <= n; i++)
        weight[i] = INF;
    q.push(make_pair(0, x));
    weight[x] = 0;
    while (!q.empty())
    {
        long long cost = -q.top().first;
        int temp = q.top().second;
        q.pop();
        for (int i = 0; i < p[temp].size(); i++)
            if (weight[p[temp][i].first] > cost + p[temp][i].second)
            {
                weight[p[temp][i].first] = cost + p[temp][i].second;
                q.push(make_pair(-weight[p[temp][i].first], p[temp][i].first));
            }
    }
}