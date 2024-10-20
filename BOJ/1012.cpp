#include <iostream>
using namespace std;
void dfs(int a, int b, int m, int n);
bool v[50][50];
bool visited[50][50];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, m, n, k, a, b, c = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> k;
        for (int j = 0; j < m; j++)
            for (int l = 0; l < n; l++)
            {
                v[j][l] = false;
                visited[j][l] = false;
            }
        for (int j = 0; j < k; j++)
        {
            cin >> a >> b;
            v[a][b] = true;
        }
        for (int j = 0; j < m; j++)
            for (int l = 0; l < n; l++)
                if (v[j][l] == true && visited[j][l] == false)
                {
                    c++;
                    dfs(j, l, m, n);
                }
        cout << c << "\n";
        c = 0;
    }
    return 0;
}

void dfs(int a, int b, int m, int n)
{
    if (v[a][b] == true && visited[a][b] == false)
    {
        visited[a][b] = true;
        if (a > 0)
            dfs(a - 1, b, m, n);
        if (b > 0)
            dfs(a, b - 1, m, n);
        if (a < m - 1)
            dfs(a + 1, b, m, n);
        if (b < n - 1)
            dfs(a, b + 1, m, n);
    }
}