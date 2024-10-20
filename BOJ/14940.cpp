#include <iostream>
#include <queue>
using namespace std;
queue<pair<int, int>> q;
int v[1000][1000], d[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, num;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            v[i][j] = num;
            if (num == 2)
            {
                d[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x > 0 && v[x - 1][y] == 1 && d[x - 1][y] == 0)
        {
            d[x - 1][y] = d[x][y] + 1;
            q.push(make_pair(x - 1, y));
        }
        if (y > 0 && v[x][y - 1] == 1 && d[x][y - 1] == 0)
        {
            d[x][y - 1] = d[x][y] + 1;
            q.push(make_pair(x, y - 1));
        }
        if (x < n - 1 && v[x + 1][y] == 1 && d[x + 1][y] == 0)
        {
            d[x + 1][y] = d[x][y] + 1;
            q.push(make_pair(x + 1, y));
        }
        if (y < m - 1 && v[x][y + 1] == 1 && d[x][y + 1] == 0)
        {
            d[x][y + 1] = d[x][y] + 1;
            q.push(make_pair(x, y + 1));
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (v[i][j] == 1 && d[i][j] == 0)
                cout << -1 << " ";
            else
                cout << d[i][j] << " ";
        cout << "\n";
    }
    return 0;
}