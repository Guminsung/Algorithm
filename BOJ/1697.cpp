#include <iostream>
#include <queue>
using namespace std;
bool visited[200000];
int pre[200000];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, cnt = 0;
    cin >> n >> k;
    visited[n] = true;
    q.push(n);
    while (q.size() > 0)
    {
        int temp = q.front();
        q.pop();
        if ((temp + 1) <= k && visited[temp + 1] == false)
        {
            pre[temp + 1] = temp;
            visited[temp + 1] = true;
            q.push(temp + 1);
        }
        if ((temp - 1) >= 0 && visited[temp - 1] == false)
        {
            pre[temp - 1] = temp;
            visited[temp - 1] = true;
            q.push(temp - 1);
        }
        if ((temp * 2) < k * 2 && visited[temp * 2] == false)
        {
            pre[temp * 2] = temp;
            visited[temp * 2] = true;
            q.push(temp * 2);
        }
    }
    while (k != n)
    {
        cnt++;
        k = pre[k];
    }
    cout << cnt;
    return 0;
}