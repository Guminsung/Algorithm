#include <iostream>
using namespace std;
char tile(int x, int y);
string v[500];
int n, m, k, cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    char c[500][500];
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v[i] = s;
    }
    for (int x = 0; x < k; x++)
        for (int y = 0; y < k; y++)
            c[x][y] = tile(x, y);
    cout << cnt << "\n";
    for (int i = 0; i < n; i += k)
        for (int x = 0; x < k; x++)
        {
            for (int j = 0; j < m; j += k)
                for (int y = 0; y < k; y++)
                    cout << c[x][y];
            cout << "\n";
        }
    return 0;
}

char tile(int x, int y)
{
    int mx = -1;
    int visited[26] = {0};
    char c;
    for (int i = x; i < n; i += k)
        for (int j = y; j < m; j += k)
            visited[(int)v[i][j] - 65]++;
    for (int i = 0; i < 26; i++)
        if (mx < visited[i])
        {
            mx = visited[i];
            c = (char)(i + 65);
        }
    cnt += n * m / (k * k) - mx;
    return c;
}