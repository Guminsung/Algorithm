#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, num;
    vector<vector<int>> a, b, c;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            v.push_back(num);
        }
        a.push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            v.push_back(num);
        }
        b.push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < m; j++)
        {
            num = a[i][j] + b[i][j];
            v.push_back(num);
        }
        c.push_back(v);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}