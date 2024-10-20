#include <iostream>
using namespace std;
int a[300][300];
int b[300][300];
int c[300][300];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            a[i][j] = num;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            b[i][j] = num;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int sm = 0;
            for (int k = 0; k < n; k++)
                sm += a[i][k] * b[k][j];
            c[i][j] = sm;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (c[i][j] != 0)
                cnt++;
    cout << cnt;
    return 0;
}