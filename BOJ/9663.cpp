#include <iostream>
using namespace std;

int c = 0;
int v[15][15] = {0};

void queen_search(int n, int i);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 0; i < 15; i++)
    {
        v[0][i] = 1;
        v[i][0] = 1;
    }
    int n;
    cin >> n;
    queen_search(n, 1);
    cout << c;
    return 0;
}

void queen_search(int n, int i)
{
    if (i <= n)
    {
        for (int j = 1; j <= n; j++)
        {
            if (v[i][j] == 0)
            {
                for (int k = 1; k <= n; k++)
                {
                    v[i][k]++;
                }
                for (int k = 1; k <= n; k++)
                {
                    v[k][j]++;
                }
                for (int k = 1; k <= n - i; k++)
                {
                    if (j - k > 0)
                        v[i + k][j - k]++;
                    else
                        break;
                }
                for (int k = 1; k <= n - i; k++)
                {
                    if (j + k <= n)
                        v[i + k][j + k]++;
                    else
                        break;
                }
                queen_search(n, i + 1);
                for (int k = 1; k <= n; k++)
                {
                    v[i][k]--;
                }
                for (int k = 1; k <= n; k++)
                {
                    v[k][j]--;
                }
                for (int k = 1; k <= n - i; k++)
                {
                    if (j - k > 0)
                        v[i + k][j - k]--;
                    else
                        break;
                }
                for (int k = 1; k <= n - i; k++)
                {
                    if (j + k <= n)
                        v[i + k][j + k]--;
                    else
                        break;
                }
            }
            else
                continue;
        }
    }
    else
    {
        c++;
    }
}