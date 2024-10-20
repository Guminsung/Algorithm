#include <iostream>
using namespace std;
int bottom_up(int n);
int DP[100][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << bottom_up(n);
    return 0;
}

int bottom_up(int n)
{
    int sum = 0;
    for (int i = 1; i <= 9; i++)
    {
        DP[0][i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
                DP[i][j] = DP[i - 1][j + 1] % 1000000000;
            else if (j == 9)
                DP[i][j] = DP[i - 1][j - 1] % 1000000000;
            else
                DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        sum += DP[n - 1][i];
        sum %= 1000000000;
    }
    return sum;
}