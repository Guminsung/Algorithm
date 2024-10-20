#include <iostream>
using namespace std;
int v1[100][100], v2[100][100], v[100][100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, num, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            v1[i][j] = num;
        }
    cin >> m >> k;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
        {
            cin >> num;
            v2[i][j] = num;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
        {
            for (int l = 0; l < m; l++)
                sum += v1[i][l] * v2[l][j];
            v[i][j] = sum;
            sum = 0;
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}