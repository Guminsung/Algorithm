#include <iostream>
using namespace std;
int a[20];
int b[20];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, m, num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m;
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            a[j] = num;
        }
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            b[j] = num;
        }
        if (n >= m)
        {
            int max;
            for (int j = 0; j <= n - m; j++)
            {
                int sum = 0;
                for (int k = 0; k < m; k++)
                    sum += a[k + j] * b[k];
                if (j == 0)
                    max = sum;
                else if (max < sum)
                    max = sum;
            }
            cout << "#" << i + 1 << " " << max << "\n";
        }
        else
        {
            int max;
            for (int j = 0; j <= m - n; j++)
            {
                int sum = 0;
                for (int k = 0; k < n; k++)
                    sum += a[k] * b[k + j];
                if (j == 0)
                    max = sum;
                else if (max < sum)
                    max = sum;
            }
            cout << "#" << i + 1 << " " << max << "\n";
        }
    }
    return 0;
}