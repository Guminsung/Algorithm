#include <iostream>
using namespace std;
int triangle(int n);
int v[501][501];
int DP[501][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> num;
            v[i][j] = num;
        }
    }
    cout << triangle(n);
    return 0;
}

int triangle(int n)
{
    DP[0][0] = v[0][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int max;
            if (j == 0)
                max = DP[i - 1][j];
            else if (j == i)
                max = DP[i - 1][j - 1];
            else
            {
                if (DP[i - 1][j - 1] > DP[i - 1][j])
                    max = DP[i - 1][j - 1];
                else
                    max = DP[i - 1][j];
            }
            DP[i][j] = v[i][j] + max;
        }
    }
    int max = -1;
    for (int i = 0; i < n; i++)
    {
        if (max < DP[n - 1][i])
            max = DP[n - 1][i];
    }
    return max;
}