#include <iostream>
using namespace std;
int v[1000];
int s[1000];
pair<int, int> dp[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, max = 0, temp, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
        dp[i].first = -1;
    }
    dp[0].second = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i].second = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i] && dp[i].second < dp[j].second + 1)
            {
                dp[i].first = j;
                dp[i].second = dp[j].second + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (max < dp[i].second)
        {
            max = dp[i].second;
            temp = i;
        }
    }
    cout << max << "\n";
    s[cnt++] = v[temp];
    while (dp[temp].first != -1)
    {
        temp = dp[temp].first;
        s[cnt++] = v[temp];
    }
    for (int i = cnt - 1; i >= 0; i--)
    {
        cout << s[i] << " ";
    }
    return 0;
}