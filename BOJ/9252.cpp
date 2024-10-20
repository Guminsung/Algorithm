#include <iostream>
#include <string>
using namespace std;
pair<int, pair<int, int>> dp[1001][1001];
char c[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s1, s2;
    int cnt = 0;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
        for (int j = 0; j < s2.size(); j++)
            dp[i][j].second = make_pair(-1, -1);
    for (int i = 0; i < s1.size(); i++)
        for (int j = 0; j < s2.size(); j++)
        {
            if (s1[i] == s2[j])
                dp[i + 1][j + 1] = make_pair(dp[i][j].first + 1, make_pair(i, j));
            else if (dp[i + 1][j] < dp[i][j + 1])
                dp[i + 1][j + 1] = dp[i][j + 1];
            else
                dp[i + 1][j + 1] = dp[i + 1][j];
        }
    int max = -1;
    pair<int, int> temp;
    for (int i = 1; i <= s1.size(); i++)
        for (int j = 1; j <= s2.size(); j++)
            if (dp[i][j].first > max)
            {
                max = dp[i][j].first;
                temp = dp[i][j].second;
            }
    cout << max << "\n";
    while (temp.first != -1 && temp.second != -1)
    {
        c[cnt++] = s1[temp.first];
        temp = dp[temp.first][temp.second].second;
    }
    for (int i = cnt - 1; i >= 0; i--)
        cout << c[i];
    return 0;
}