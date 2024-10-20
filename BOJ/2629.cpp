#include <iostream>
using namespace std;
void Knapsack(int n);
int w[30];
int b[7];
bool dp[30][40001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        w[i] = num;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        b[i] = num;
    }
    Knapsack(n);
    for (int i = 0; i < m; i++)
    {
        if (dp[n - 1][b[i]] == true)
            cout << "Y"
                 << " ";
        else
            cout << "N"
                 << " ";
    }
    return 0;
}

void Knapsack(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 40000; j > 0; j--)
        {
            if (j == w[i])
                dp[i][w[i]] = true;
            if (i > 0 && dp[i - 1][j] == true)
            {
                if (j - w[i] > 0)
                    dp[i][j - w[i]] = true;
                else
                    dp[i][w[i] - j] = true;
                if (j + w[i] <= 40000)
                    dp[i][j + w[i]] = true;
                dp[i][j] = true;
            }
        }
}