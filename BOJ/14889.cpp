#include <iostream>
#include <cstdlib>
using namespace std;

void sl(int n, int x, int c);

int v[20][20];
bool s[20];
int sl_min = 100;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            v[i][j] = num;
        }
    }
    sl(n, 1, 0);
    cout << sl_min;
    return 0;
}

void sl(int n, int x, int c)
{
    if (c == n / 2)
    {
        int sum_s = 0, sum_l = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i + 1] == true)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (s[j + 1] == true)
                    {
                        sum_s += v[i][j];
                        sum_s += v[j][i];
                    }
                }
            }
            if (s[i + 1] == false)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (s[j + 1] == false)
                    {
                        sum_l += v[i][j];
                        sum_l += v[j][i];
                    }
                }
            }
        }
        if (sl_min > abs(sum_s - sum_l))
            sl_min = abs(sum_s - sum_l);
    }
    else
    {
        for (int i = x; i <= n; i++)
        {
            if (x > n / 2 && c == 0)
                break;
            s[i] = true;
            sl(n, i + 1, c + 1);
            s[i] = false;
        }
    }
}