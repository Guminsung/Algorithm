#include <iostream>
using namespace std;
int Knapsack(int n, int k);
int DP[1000001];
pair<int, int> p[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, w, v;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> w >> v;
        p[i] = make_pair(w, v);
    }
    cout << Knapsack(n, k);
    return 0;
}

int Knapsack(int n, int k)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        for (int j = k; j >= 1; j--)
            if (j - p[i].first >= 0)
                if (DP[j] < DP[j - p[i].first] + p[i].second)
                    DP[j] = DP[j - p[i].first] + p[i].second;
    int max = 0;
    for (int i = 1; i <= k; i++)
        if (max < DP[i])
            max = DP[i];
    return max;
}