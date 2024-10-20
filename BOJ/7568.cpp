#include <iostream>
using namespace std;
int v[50][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, y, cnt = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v[i][0] = x;
        v[i][1] = y;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i != j && v[i][0] < v[j][0] && v[i][1] < v[j][1])
                cnt++;
        cout << cnt << " ";
        cnt = 1;
    }
    return 0;
}