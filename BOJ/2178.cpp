#include <iostream>
#include <queue>
using namespace std;
int maze[101][101];
bool visited[101][101];
pair<int, int> predecessor[101][101];
queue<pair<int, int>> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, cnt = 0;
    string s;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == '0')
                maze[i][j + 1] = 0;
            else
                maze[i][j + 1] = 1;
    }
    int x = 1, y = 1;
    q.push(make_pair(x, y));
    while (q.size() > 0)
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (x > 1 && visited[x - 1][y] == false && maze[x - 1][y] == 1)
        {
            visited[x - 1][y] = true;
            predecessor[x - 1][y] = make_pair(x, y);
            q.push(make_pair(x - 1, y));
        }
        if (y > 1 && visited[x][y - 1] == false && maze[x][y - 1] == 1)
        {
            visited[x][y - 1] = true;
            predecessor[x][y - 1] = make_pair(x, y);
            q.push(make_pair(x, y - 1));
        }
        if (x < n && visited[x + 1][y] == false && maze[x + 1][y] == 1)
        {
            visited[x + 1][y] = true;
            predecessor[x + 1][y] = make_pair(x, y);
            q.push(make_pair(x + 1, y));
        }
        if (y < m && visited[x][y + 1] == false && maze[x][y + 1] == 1)
        {
            visited[x][y + 1] = true;
            predecessor[x][y + 1] = make_pair(x, y);
            q.push(make_pair(x, y + 1));
        }
    }
    x = n, y = m;
    while (x != 1 || y != 1)
    {
        cnt++;
        pair<int, int> temp = predecessor[x][y];
        x = temp.first;
        y = temp.second;
    }
    cout << cnt + 1;
    return 0;
}