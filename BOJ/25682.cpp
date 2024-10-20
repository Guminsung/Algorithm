#include <iostream>
using namespace std;
char chess[2001][2001];
int PS1[2001][2001];
int PS2[2001][2001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, min = 2000001;
    char c;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            chess[i][j] = c;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i % 2 == 0)
            {
                if ((chess[i][j] == 'B' && j % 2 == 0) || (chess[i][j] == 'W' && j % 2 == 1))
                    PS1[i][j] = PS1[i][j - 1] + 1;
                else
                    PS1[i][j] = PS1[i][j - 1];
            }
            else
            {
                if ((chess[i][j] == 'B' && j % 2 == 1) || (chess[i][j] == 'W' && j % 2 == 0))
                    PS1[i][j] = PS1[i][j - 1] + 1;
                else
                    PS1[i][j] = PS1[i][j - 1];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            PS2[i][j] = PS2[i - 1][j] + PS1[i][j];
    for (int i = k; i <= n; i++)
    {
        for (int j = k; j <= m; j++)
        {
            int result;
            result = PS2[i][j] - PS2[i - k][j] - PS2[i][j - k] + PS2[i - k][j - k];
            if (result > k * k / 2)
                result = k * k - result;
            if (min > result)
                min = result;
        }
    }
    cout << min;
    return 0;
}