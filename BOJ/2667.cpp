#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void danzi(int n);
void dfs(int x, int y, int n);
int m[25][25];
bool visited[25][25];
vector<int> v;
int cnt = 0, c = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            if (s[j] == '0')
                m[i][j] = 0;
            else
                m[i][j] = 1;
    }
    danzi(n);
    sort(v.begin(), v.end());
    cout << cnt << "\n";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "\n";
    return 0;
}

void danzi(int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == false && m[i][j] == 1)
            {
                cnt++;
                dfs(i, j, n);
                v.push_back(c);
                c = 0;
            }
        }
}

void dfs(int x, int y, int n)
{
    visited[x][y] = true;
    c++;
    if (x > 0 && visited[x - 1][y] == false && m[x - 1][y] == 1)
        dfs(x - 1, y, n);
    if (y > 0 && visited[x][y - 1] == false && m[x][y - 1] == 1)
        dfs(x, y - 1, n);
    if (x < n - 1 && visited[x + 1][y] == false && m[x + 1][y] == 1)
        dfs(x + 1, y, n);
    if (y < n - 1 && visited[x][y + 1] == false && m[x][y + 1] == 1)
        dfs(x, y + 1, n);
}