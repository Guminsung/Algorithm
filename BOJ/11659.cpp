#include <iostream>
using namespace std;
int v[100001];
int PS[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, num, i, j;
    cin >> n >> m;
    for (int k = 1; k <= n; k++)
    {
        cin >> num;
        v[k] = num;
    }
    for (int k = 1; k <= n; k++)
        PS[k] = PS[k - 1] + v[k];
    for (int k = 0; k < m; k++)
    {
        cin >> i >> j;
        cout << PS[j] - PS[i - 1] << "\n";
    }
    return 0;
}