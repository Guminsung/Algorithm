#include <iostream>
using namespace std;
int v[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, i = 0;
    bool f;
    cin >> m >> n;
    while (m <= n)
    {
        f = true;
        for (int j = 2; j * j <= m; j++)
        {
            if (m % j == 0)
            {
                f = false;
                break;
            }
        }
        if (f == true && m != 0 && m != 1)
        {
            v[i++] = m;
        }
        m++;
    }
    for(int j=0;j<i;j++)
    {
        cout << v[j] << "\n";
    }
    return 0;
}