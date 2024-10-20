#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
int v[200001];
int INF = 100000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= 200000; i++)
        v[i] = INF;
    q.push(make_pair(0, n));
    v[n] = 0;
    while (!q.empty())
    {
        int cost = -q.front().first, temp = q.front().second;
        q.pop();
        if ((temp * 2) < k * 2 && v[temp * 2] > cost)
        {
            v[temp * 2] = cost;
            q.push(make_pair(-cost, temp * 2));
        }
        if ((temp + 1) <= k && v[temp + 1] > cost + 1)
        {
            v[temp + 1] = cost + 1;
            q.push(make_pair(-(cost + 1), temp + 1));
        }
        if ((temp - 1) >= 0 && v[temp - 1] > cost + 1)
        {
            v[temp - 1] = cost + 1;
            q.push(make_pair(-(cost + 1), temp - 1));
        }
    }
    cout << v[k];
    return 0;
}