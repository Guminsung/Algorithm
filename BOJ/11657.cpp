#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
vector<tuple<int, int, int>> v;
long long d[501];
int INF = 50000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b, c;
    bool tm = true;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v.push_back(make_tuple(a, b, c));
    }
    for (int i = 2; i <= n; i++)
        d[i] = INF;
    d[1] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            int x = get<0>(v[j]), y = get<1>(v[j]);
            long long cost = get<2>(v[j]);
            if (d[x] != INF && d[x] + cost < d[y])
                d[y] = d[x] + cost;
        }
    }
    for (int j = 0; j < v.size(); j++)
    {
        int x = get<0>(v[j]), y = get<1>(v[j]);
        long long cost = get<2>(v[j]);
        if (d[x] != INF && d[x] + cost < d[y])
            tm = false;
    }
    if (tm == true)
        for (int i = 2; i <= n; i++)
        {
            if (d[i] != INF)
                cout << d[i] << "\n";
            else
                cout << -1 << "\n";
        }
    else
        cout << -1;
    return 0;
}