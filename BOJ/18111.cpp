#include <iostream>
using namespace std;
int v[500][500];
int t[257];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, b, num, h, all_sum = 0;
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            v[i][j] = num;
            all_sum += num;
        }
    for (int k = 0; k <= 256; k++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (n * m * k <= all_sum + b)
                    if (v[i][j] > k)
                        sum += (v[i][j] - k) * 2;
                    else
                        sum += k - v[i][j];
                else
                    sum = -1;
            }
        t[k] = sum;
    }
    int min = t[0];
    for (int i = 0; i < 257; i++)
        if (t[i] != -1 && min >= t[i])
        {
            min = t[i];
            h = i;
        }
    cout << min << " " << h;
    return 0;
}