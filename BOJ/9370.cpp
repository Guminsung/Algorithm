#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int INF = 2000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, n, m, t, s, g, h, a, b, d, num;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        vector<vector<pair<int, int>>> p(2001);
        priority_queue<pair<int, int>> q;
        vector<int> v;
        int weight[2001];
        cin >> n >> m >> t >> s >> g >> h;
        for (int j = 0; j < m; j++)
        {
            cin >> a >> b >> d;
            if ((a == g && b == h) || (a == h && b == g))
            {
                p[a].push_back(make_pair(b, d * 2 - 1));
                p[b].push_back(make_pair(a, d * 2 - 1));
            }
            else
            {
                p[a].push_back(make_pair(b, d * 2));
                p[b].push_back(make_pair(a, d * 2));
            }
        }
        for (int j = 0; j < t; j++)
        {
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        for (int i = 1; i <= n; i++)
            weight[i] = INF;
        q.push(make_pair(0, s));
        weight[s] = 0;
        while (!q.empty())
        {
            int cost = -q.top().first, temp = q.top().second;
            q.pop();
            for (int j = 0; j < p[temp].size(); j++)
                if (weight[p[temp][j].first] > cost + p[temp][j].second)
                {
                    weight[p[temp][j].first] = cost + p[temp][j].second;
                    q.push(make_pair(-weight[p[temp][j].first], p[temp][j].first));
                }
        }
        for (int j = 0; j < v.size(); j++)
            if (weight[v[j]] % 2 == 1)
                cout << v[j] << " ";
        cout << "\n";
        for (int j = 1; j <= n; j++)
            while (p[j].size() > 0)
                p[j].pop_back();
        while (v.size() > 0)
            v.pop_back();
    }
    return 0;
}