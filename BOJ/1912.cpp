#include <iostream>
using namespace std;
void sum(int n);
int v[100000];
int dp[100000];
int Max = -1001;

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
        if (Max < num)
            Max = num;
    }
    sum(n);
    cout << Max;
    return 0;
}

void sum(int n)
{
    dp[1] = v[0] + v[1];
    for (int i = 1; i < n - 1; i++)
    {
        if (dp[i] < 0)
            dp[i + 1] = v[i + 1];
        else
            dp[i + 1] = v[i + 1] + dp[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (Max < dp[i])
            Max = dp[i];
    }
}