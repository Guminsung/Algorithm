#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
int v[101];
int pre[101];
bool visited[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x, y, num = 100, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        cin >> x >> y;
        v[x] = y;
    }
    q.push(1);
    visited[1] = true;
    while (q.size() > 0)
    {
        int temp = q.front();
        q.pop();
        for (int i = 1; i <= 6; i++)
            if (temp + i <= 100 && visited[temp + i] == false)
                if (v[temp + i] == 0)
                {
                    q.push(temp + i);
                    visited[temp + i] = true;
                    pre[temp + i] = temp;
                }
                else
                {
                    visited[temp + i] = true;
                    if (visited[v[temp + i]] == false)
                    {
                        q.push(v[temp + i]);
                        visited[v[temp + i]] = true;
                        pre[v[temp + i]] = temp;
                    }
                }
    }
    while (num > 1)
    {
        num = pre[num];
        cnt++;
    }
    cout << cnt;
    return 0;
}