#include <iostream>
#include <vector>
using namespace std;
void dfs(int n);
bool visited[101];
vector<vector<int>> v(101);
int cnt = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
    cout << cnt;
    return 0;
}

void dfs(int n)
{
    visited[n] = true;
    cnt++;
    for (int i = 0; i < v[n].size(); i++)
        if (visited[v[n][i]] == false)
            dfs(v[n][i]);
}