#include <iostream>
#include <vector>
using namespace std;
void route(int s, int e);
vector<int> temp;
int v[101][101];
int visited[101][101];
int INF = 999999999;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b, cost, s, e;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            v[i][j] = INF;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> cost;
        if (v[a][b] > cost)
            v[a][b] = cost;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (j != k && v[j][i] + v[i][k] < v[j][k])
                {
                    v[j][k] = v[j][i] + v[i][k];
                    visited[j][k] = i;
                }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (v[i][j] == INF)
                v[i][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (v[i][j] == 0)
                cout << 0 << "\n";
            else
            {
                route(i, j);
                cout << temp.size() << " ";
                while (!temp.empty())
                {
                    cout << temp[temp.size() - 1] << " ";
                    temp.pop_back();
                }
                cout << "\n";
            }
        }
    }
    return 0;
}

void route(int s, int e)
{
    int m = visited[s][e];
    if (visited[s][e] == 0)
    {
        temp.push_back(e);
        temp.push_back(s);
        return;
    }
    route(m, e);
    temp.pop_back();
    route(s, m);
}