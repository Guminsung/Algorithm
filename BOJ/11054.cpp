#include <iostream>
using namespace std;
int Bitonic(int n);
int v[1000];
int DP_L[1000];
int DP_R[1000];

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
    cout << Bitonic(n);
    return 0;
}

int Bitonic(int n)
{
    for (int i = 0; i < n; i++)
    {
        DP_L[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[j] < v[i])
                if (DP_L[i] < DP_L[j] + 1)
                    DP_L[i] = DP_L[j] + 1;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        DP_R[i] = 1;
        for (int j = n - 1; j > i; j--)
        {
            if (v[j] < v[i])
                if (DP_R[i] < DP_R[j] + 1)
                    DP_R[i] = DP_R[j] + 1;
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < (DP_L[i] + DP_R[i] - 1))
            max = DP_L[i] + DP_R[i] - 1;
    }
    return max;
}