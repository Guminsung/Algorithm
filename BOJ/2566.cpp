#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, n, m, max = -1;
    vector<vector<int>> v2;
    for (int i = 0; i < 9; i++)
    {
        vector<int> v;
        for (int j = 0; j < 9; j++)
        {
            cin >> num;
            v.push_back(num);
        }
        v2.push_back(v);
    }
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (v2[i][j] > max)
            {
                max = v2[i][j];
                n = i + 1;
                m = j + 1;
            }
        }
    }
    cout << max << endl
         << n << " " << m;
    return 0;
}