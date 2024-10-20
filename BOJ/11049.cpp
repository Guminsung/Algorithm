#include <iostream>
using namespace std;
pair<int, int> v[500];
int dp[500][500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, r, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r >> c;
        v[i].first = r;
        v[i].second = c;
    }
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int i = 0; i < n - 1; i++)
        dp[i][i + 1] = v[i].first * v[i].second * v[i + 1].second;
    for (int i = 2; i < n; i++)
        for (int j = 0; j < n - i; j++)
        {
            int min = 2147483647;
            for (int l = j; l < j + i; l++)
            {
                int temp = dp[j][l] + dp[l + 1][j + i] + v[j].first * v[l].second * v[j + i].second;
                if (temp < min)
                    min = temp;
            }
            dp[j][j + i] = min;
        }
    cout << dp[0][n - 1] << "\n";
    return 0;
}