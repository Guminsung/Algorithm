#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<char>> v2;
    int n, m, count = 0, min = 32;
    char c, s;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<char> v1;
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            v1.push_back(c);
        }
        v2.push_back(v1);
    }
    for (int k = 0; k <= n - 8; k++)
    {
        for (int l = 0; l <= m - 8; l++)
        {
            for (int i = k; i < k + 8; i++)
            {
                if (s == 'W')
                    s = 'B';
                else
                    s = 'W';
                for (int j = l; j < l + 8; j++)
                {
                    if (j % 2 == 0 && v2[i][j] != s)
                        count++;
                    else if (j % 2 == 1 && v2[i][j] == s)
                        count++;
                    else
                        continue;
                }
            }
            if (count > 32)
                count = 64 - count;
            if (count < min)
                min = count;
            count = 0;
        }
    }
    cout << min;
    return 0;
}