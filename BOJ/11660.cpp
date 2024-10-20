#include <iostream>
using namespace std;
int v[1025][1025];
int PS[1025][1025];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, num, x1, x2, y1, y2;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> num;
            v[i][j] = num;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            PS[i][j] = PS[i][j - 1] + v[i][j];
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = x1; i <= x2; i++)
            sum += PS[i][y2] - PS[i][y1 - 1];
        cout << sum << "\n";
    }
    return 0;
}