#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int v[100][100][100];
tuple<int, int, int> pre[100][100][100];
queue<tuple<int, int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m, n, h, num, cnt = 0;
    bool visited = false;
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> num;
                v[i][j][k] = num;
                pre[i][j][k] = make_tuple(-1, -1, -1);
                if (num == 1)
                    q.push(make_tuple(i, j, k));
            }
    while (q.size() > 0)
    {
        int x = get<0>(q.front()), y = get<1>(q.front()), z = get<2>(q.front());
        q.pop();
        if (x > 0 && v[x - 1][y][z] == 0)
        {
            v[x - 1][y][z] = 1;
            pre[x - 1][y][z] = make_tuple(x, y, z);
            q.push(make_tuple(x - 1, y, z));
        }
        if (y > 0 && v[x][y - 1][z] == 0)
        {
            v[x][y - 1][z] = 1;
            pre[x][y - 1][z] = make_tuple(x, y, z);
            q.push(make_tuple(x, y - 1, z));
        }
        if (z > 0 && v[x][y][z - 1] == 0)
        {
            v[x][y][z - 1] = 1;
            pre[x][y][z - 1] = make_tuple(x, y, z);
            q.push(make_tuple(x, y, z - 1));
        }
        if (x < n - 1 && v[x + 1][y][z] == 0)
        {
            v[x + 1][y][z] = 1;
            pre[x + 1][y][z] = make_tuple(x, y, z);
            q.push(make_tuple(x + 1, y, z));
        }
        if (y < m - 1 && v[x][y + 1][z] == 0)
        {
            v[x][y + 1][z] = 1;
            pre[x][y + 1][z] = make_tuple(x, y, z);
            q.push(make_tuple(x, y + 1, z));
        }
        if (z < h - 1 && v[x][y][z + 1] == 0)
        {
            v[x][y][z + 1] = 1;
            pre[x][y][z + 1] = make_tuple(x, y, z);
            q.push(make_tuple(x, y, z + 1));
        }
        if (q.size() == 0)
            while (pre[x][y][z] != make_tuple(-1, -1, -1))
            {
                int tx = get<0>(pre[x][y][z]), ty = get<1>(pre[x][y][z]), tz = get<2>(pre[x][y][z]);
                x = tx, y = ty, z = tz;
                cnt++;
            }
    }
    for (int k = 0; k < h; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (v[i][j][k] == 0)
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