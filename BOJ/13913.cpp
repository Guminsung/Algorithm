#include <iostream>
#include <queue>
using namespace std;
int visited[200000];
int v[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, cnt = 0;
    queue<int> q;
    cin >> n >> k;
    for (int i = 0; i < 200000; i++)
        visited[i] = -1;
    q.push(n);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x > 0 && visited[x - 1] == -1)
        {
            q.push(x - 1);
            visited[x - 1] = x;
        }
        if (x < k)
        {
            if (visited[x + 1] == -1)
            {
                q.push(x + 1);
                visited[x + 1] = x;
            }
            if (visited[x * 2] == -1)
            {
                q.push(x * 2);
                visited[x * 2] = x;
            }
        }
    }
    int temp = k;
    while (temp != n)
    {
        v[cnt++] = temp;
        temp = visited[temp];
    }
    v[cnt++] = n;
    cout << cnt - 1 << "\n";
    for (int i = cnt - 1; i >= 0; i--)
        cout << v[i] << " ";
    return 0;
}