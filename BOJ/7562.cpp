#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, a, b, x, y;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        queue<pair<int, int>> q;
        pair<int, int> pre[300][300] = {make_pair(0, 0)};
        bool visited[300][300] = {false};
        int cnt = 0;
        cin >> n >> a >> b >> x >> y;
        q.push(make_pair(a, b));
        visited[a][b] = true;
        while (q.size() > 0)
        {
            int temp_x = q.front().first, temp_y = q.front().second;
            q.pop();

            if ((temp_x + 1 < n) && (temp_y + 2 < n) && visited[temp_x + 1][temp_y + 2] == false)
            {
                visited[temp_x + 1][temp_y + 2] = true;
                pre[temp_x + 1][temp_y + 2] = make_pair(temp_x, temp_y);
                q.push(make_pair(temp_x + 1, temp_y + 2));
            }
            if ((temp_x + 2 < n) && (temp_y + 1 < n) && visited[temp_x + 2][temp_y + 1] == false)
            {
                visited[temp_x + 2][temp_y + 1] = true;
                pre[temp_x + 2][temp_y + 1] = make_pair(temp_x, temp_y);
                q.push(make_pair(temp_x + 2, temp_y + 1));
            }

            if ((temp_x - 1 >= 0) && (temp_y + 2 < n) && visited[temp_x - 1][temp_y + 2] == false)
            {
                visited[temp_x - 1][temp_y + 2] = true;
                pre[temp_x - 1][temp_y + 2] = make_pair(temp_x, temp_y);
                q.push(make_pair(temp_x - 1, temp_y + 2));
            }
            if ((temp_x - 2 >= 0) && (temp_y + 1 < n) && visited[temp_x - 2][temp_y + 1] == false)
            {
                visited[temp_x - 2][temp_y + 1] = true;
                pre[temp_x - 2][temp_y + 1] = make_pair(temp_x, temp_y);
                q.push(make_pair(temp_x - 2, temp_y + 1));
            }

            if ((temp_x + 1 < n) && (temp_y - 2 >= 0) && visited[temp_x + 1][temp_y - 2] == false)
            {
                visited[temp_x + 1][temp_y - 2] = true;
                pre[temp_x + 1][temp_y - 2] = make_pair(temp_x, temp_y);
                q.push(make_pair(temp_x + 1, temp_y - 2));
            }
            if ((temp_x + 2 < n) && (temp_y - 1 >= 0) && visited[temp_x + 2][temp_y - 1] == false)
            {
                visited[temp_x + 2][temp_y - 1] = true;
                pre[temp_x + 2][temp_y - 1] = make_pair(temp_x, temp_y);
                q.push(make_pair(temp_x + 2, temp_y - 1));
            }

            if ((temp_x - 1 >= 0) && (temp_y - 2 >= 0) && visited[temp_x - 1][temp_y - 2] == false)
            {
                visited[temp_x - 1][temp_y - 2] = true;
                pre[temp_x - 1][temp_y - 2] = make_pair(temp_x, temp_y);
                q.push(make_pair(temp_x - 1, temp_y - 2));
            }
            if ((temp_x - 2 >= 0) && (temp_y - 1 >= 0) && visited[temp_x - 2][temp_y - 1] == false)
            {
                visited[temp_x - 2][temp_y - 1] = true;
                pre[temp_x - 2][temp_y - 1] = make_pair(temp_x, temp_y);
                q.push(make_pair(temp_x - 2, temp_y - 1));
            }
        }
        while (a != x || b != y)
        {
            cnt++;
            int temp_x = pre[x][y].first, temp_y = pre[x][y].second;
            x = temp_x;
            y = temp_y;
        }
        cout << cnt << "\n";
    }
    return 0;
}