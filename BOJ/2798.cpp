#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, num, max = 0;
    vector<int> v;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (j > i)
                for (int k = 2; k < n; k++)
                {
                    if (k > j)
                        if ((max < (v[i] + v[j] + v[k])) && (v[i] + v[j] + v[k] <= m))
                            max = v[i] + v[j] + v[k];
                }
        }
    }
    cout << max;
    return 0;
}