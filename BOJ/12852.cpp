#include <iostream>
#include <queue>
using namespace std;
pair<int, int> dp[1000001];
int v[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<pair<int, int>> q;
    int n, c = 0;
    cin >> n;
    q.push(make_pair(n, 0));
    while (!q.empty())
    {
        int x = q.front().first, cnt = q.front().second;
        q.pop();
        if (x > 0)
        {
            if (x % 3 == 0 && (dp[x / 3].first == 0 || dp[x / 3].second > cnt))
            {
                dp[x / 3] = make_pair(x, cnt + 1);
                q.push(make_pair(x / 3, cnt + 1));
            }
            if (x % 2 == 0 && (dp[x / 2].first == 0 || dp[x / 2].second > cnt))
            {
                dp[x / 2] = make_pair(x, cnt + 1);
                q.push(make_pair(x / 2, cnt + 1));
            }
            if ((dp[x - 1].first == 0 || dp[x - 1].second > cnt))
            {
                dp[x - 1] = make_pair(x, cnt + 1);
                q.push(make_pair(x - 1, cnt + 1));
            }
        }
    }
    int temp = 1;
    v[c++] = temp;
    cout << dp[temp].second << "\n";
    while (temp != n)
    {
        temp = dp[temp].first;
        v[c++] = temp;
    }
    for (int i = c - 1; i >= 0; i--)
        cout << v[i] << " ";
    return 0;
}