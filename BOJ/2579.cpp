#include <iostream>
using namespace std;
int stair(int n);
int v[300];
int DP[300][2];

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
    cout << stair(n);
    return 0;
}

int stair(int n)
{
    DP[0][0] = v[0];
    DP[0][1] = v[0];
    DP[1][0] = v[1] + v[0];
    DP[1][1] = v[1];
    for (int i = 2; i < n; i++)
    {
        DP[i][0] = DP[i - 1][1] + v[i];
        DP[i - 2][0] > DP[i - 2][1] ? DP[i][1] = DP[i - 2][0] + v[i] : DP[i][1] = DP[i - 2][1] + v[i];
    }
    if (DP[n - 1][0] > DP[n - 1][1])
        return DP[n - 1][0];
    else
        return DP[n - 1][1];
}