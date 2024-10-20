#include <iostream>
using namespace std;
int v[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, c;
    for (int i = 2; i <= 1000000; i++)
    {
        v[i] = i;
    }
    for (int i = 2; i <= 1000; i++)
    {
        if (v[i] != 0)
        {
            for (int j = 2; j * i <= 1000000; j++)
            {
                v[j * i] = 0;
            }
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        c = 0;
        cin >> n;
        for (int j = 2; j < n; j++)
        {
            if (v[n - j] + v[j] == n)
            {
                c++;
                if (n == 2 * j)
                    c++;
            }
        }
        cout << c / 2 << "\n";
    }
    return 0;
}