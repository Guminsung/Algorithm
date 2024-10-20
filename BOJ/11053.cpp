#include <iostream>
using namespace std;
int LIS(int n);
int v[1000];
int DP[1000];

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
    cout << LIS(n);
    return 0;
}

int LIS(int n)
{
    for (int i = 0; i < n; i++)
    {
        DP[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
                if (DP[i] < DP[j] + 1)
                    DP[i] = DP[j] + 1;
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < DP[i])
            max = DP[i];
    }
    return max;
}