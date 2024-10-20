#include <iostream>
using namespace std;
void app(int N);
int m[100];
int c[100];
int dp[100][10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, num;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        m[i] = num;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        c[i] = num;
    }
    app(N);
    for (int i = 0; i <= 10000; i++)
        if (dp[N - 1][i] >= M)
        {
            cout << i;
            break;
        }
    return 0;
}

void app(int N)
{
    for (int i = 0; i < N; i++)
    {
        dp[i][c[i]] = m[i];
        if (i > 0)
            for (int j = 0; j <= 10000; j++)
            {
                if (j - c[i] >= 0 && dp[i][j] < dp[i - 1][j - c[i]] + m[i])
                    dp[i][j] = dp[i - 1][j - c[i]] + m[i];
                if (dp[i][j] < dp[i - 1][j])
                    dp[i][j] = dp[i - 1][j];
            }
    }
}