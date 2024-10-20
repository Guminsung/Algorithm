#include <iostream>
using namespace std;
int v[15][15];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, m, num;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int max = -1;
        cin >> n >> m;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                cin >> num;
                v[j][k] = num;
            }
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                int sum1 = v[j][k], sum2 = v[j][k];
                for (int l = 1; l < m; l++)
                {
                    if (j - l >= 0)
                        sum1 += v[j - l][k];
                    if (j + l < n)
                        sum1 += v[j + l][k];
                    if (k - l >= 0)
                        sum1 += v[j][k - l];
                    if (k + l < n)
                        sum1 += v[j][k + l];
                }
                if (sum1 > max)
                    max = sum1;
                for (int l = 1; l < m; l++)
                {
                    if (j - l >= 0 && k - l >= 0)
                        sum2 += v[j - l][k - l];
                    if (j - l >= 0 && k + l < n)
                        sum2 += v[j - l][k + l];
                    if (j + l < n && k - l >= 0)
                        sum2 += v[j + l][k - l];
                    if (j + l < n && k + l < n)
                        sum2 += v[j + l][k + l];
                }
                if (sum2 > max)
                    max = sum2;
            }
        cout << "#" << i << " " << max << "\n";
    }
    return 0;
}