#include <iostream>
#include <queue>
using namespace std;
int v[1000][1000];
pair<int, int> pre[1000][1000];
queue<pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n, num, cnt = 0;
    bool visited = false;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            v[i][j] = num;
            pre[i][j] = make_pair(-1, -1);
            if (num == 1)
                q.push(make_pair(i, j));
        }
    while (q.size() > 0)
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x > 0 && v[x - 1][y] == 0)
        {
            v[x - 1][y] = 1;
            pre[x - 1][y] = make_pair(x, y);
            q.push(make_pair(x - 1, y));
        }
        if (y > 0 && v[x][y - 1] == 0)
        {
            v[x][y - 1] = 1;
            pre[x][y - 1] = make_pair(x, y);
            q.push(make_pair(x, y - 1));
        }
        if (x < n - 1 && v[x + 1][y] == 0)
        {
            v[x + 1][y] = 1;
            pre[x + 1][y] = make_pair(x, y);
            q.push(make_pair(x + 1, y));
        }
        if (y < m - 1 && v[x][y + 1] == 0)
        {
            v[x][y + 1] = 1;
            pre[x][y + 1] = make_pair(x, y);
            q.push(make_pair(x, y + 1));
        }
        if (q.size() == 0)
            while (pre[x][y] != make_pair(-1, -1))
            {
                int tx = pre[x][y].first, ty = pre[x][y].second;
                x = tx, y = ty;
                cnt++;
            }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (v[i][j] == 0)
            {
                visited = true;
                break;
            }
    if (visited == true)
        cout << -1;
    else
        cout << cnt;
    return 0;
}