#include <iostream>
using namespace std;
int bottom_up(int n);
int v[10000];
int DP[10000][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    cout << bottom_up(n);
    return 0;
}

int bottom_up(int n)
{
    for (int i = 0; i < 3; i++)
    {
        DP[0][i] = v[0];
    }
    DP[1][0] = v[0] + v[1];
    DP[1][1] = v[1];
    DP[1][2] = v[1];
    DP[2][0] = v[1] + v[2];
    DP[2][1] = v[0] + v[2];
    DP[2][2] = v[2];
    if (n == 1 || n == 2)
        return DP[n - 1][0];
    else if (n == 3)
    {
        int min = 1001, sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += v[i];
            if (v[i] < min)
                min = v[i];
        }
        return sum - min;
    }
    for (int i = 3; i < n; i++)
    {
        if (DP[i - 1][1] > DP[i - 1][2])
            DP[i][0] = DP[i - 1][1] + v[i];
        else
            DP[i][0] = DP[i - 1][2] + v[i];
        int max1 = -1;
        for (int j = 0; j < 3; j++)
        {
            if (DP[i - 2][j] > max1)
                max1 = DP[i - 2][j];
        }
        DP[i][1] = max1 + v[i];
        int max2 = -1;
        for (int j = 0; j < 3; j++)
        {
            if (DP[i - 3][j] > max2)
                max2 = DP[i - 3][j];
        }
        DP[i][2] = max2 + v[i];
    }
    int max = -1;
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (DP[n - i][j] > max)
                max = DP[n - i][j];
        }
    }
    return max;
}   