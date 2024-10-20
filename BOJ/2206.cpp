#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int bfs(int N, int M);
int v[1001][1001][2];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
queue<tuple<int, int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    string s;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        for (int j = 0; j < M; j++)
            if (s[j] == '0')
                v[i][j][0] = 0;
            else
                v[i][j][0] = 1;
    }
    cout << bfs(N, M);
}

int bfs(int N, int M)
{
    q.push(make_tuple(0, 0, 0));
    while (q.size() > 0)
    {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        if (x == N - 1 && y == M - 1)
            return v[N - 1][M - 1][z] + 1;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (v[nx][ny][0] == 1)
            {
                if (z == 0)
                {
                    v[nx][ny][1] = v[x][y][z] + 1;
                    q.push(make_tuple(nx, ny, 1));
                }
            }
            else if (v[nx][ny][0] == 0)
            {
                if (z == 1 && v[nx][ny][z] > 0)
                    continue;
                v[nx][ny][z] = v[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z));
            }
        }
    }
    return -1;
}