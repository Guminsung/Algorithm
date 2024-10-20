#include <iostream>
using namespace std;
int v[500];
int dp[500][500];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, k, num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> num;
            v[j] = num;
        }
        for (int i = 0; i < k; i++)
            dp[i][i] = 0;
        for (int i = 0; i < k - 1; i++)
            dp[i][i + 1] = v[i] + v[i + 1];
        for (int i = 2; i < k; i++)
            for (int j = 0; j < k - i; j++)
            {
                int sum = 0, min = 2147483647;
                for (int l = j; l < j + i; l++)
                {
                    int temp = dp[j][l] + dp[l + 1][j + i];
                    if (temp < min)
                        min = temp;
                }
                for (int l = j; l <= j + i; l++)
                    sum += v[l];
                sum += min;
                dp[j][j + i] = sum;
            }
        cout << dp[0][k - 1] << "\n";
    }
    return 0;
}