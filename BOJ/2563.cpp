#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x, y, sum = 0;
    vector<vector<int>> v2(100, vector<int>(100, 0));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        for (int j = x - 1; j < x + 9; j++)
        {
            for (int k = y - 1; k < y + 9; k++)
            {
                v2[j][k] = 1;
            }
        }
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (v2[i][j] == 1)
                sum++;
        }
    }
    cout << sum;
    return 0;
}