#include <iostream>
using namespace std;
int v[1000000];
int PS[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    long long num, c = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    for (int i = 1; i <= n; i++)
        PS[i] = (PS[i - 1] + v[i - 1]) % m;
    for (int i = 0; i < m; i++)
    {
        num = 0;
        for (int j = 1; j <= n; j++)
        {
            if (PS[j] == i && i == 0)
            {
                c++;
                num++;
            }
            else if (PS[j] == i)
                num++;
        }
        c += num * (num - 1) / 2;
    }
    cout << c;
    return 0;
}