#include <iostream>
using namespace std;
int v[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x, y, cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        for (int j = x; j < y; j++)
            v[j] = -1;
    }
    for (int i = 1; i <= n; i++)
        if (v[i] == 0)
            cnt++;
    cout << cnt;
    return 0;
}