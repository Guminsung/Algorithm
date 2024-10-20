#include <iostream>
#include <vector>
using namespace std;
int make_tree(int r);
vector<vector<int>> edge(100001);
int root[100001];
bool visited[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, r, q, u, v;
    cin >> n >> r >> q;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    visited[r] = true;
    make_tree(r);
    for (int i = 0; i < q; i++)
    {
        cin >> u;
        cout << root[u] << "\n";
    }
    return 0;
}

int make_tree(int r)
{
    if (root[r])
        return root[r];
    int cnt = 0;
    for (int i = 0; i < edge[r].size(); i++)
        if (!visited[edge[r][i]])
        {
            visited[edge[r][i]] = true;
            cnt += make_tree(edge[r][i]);
        }
    return root[r] = cnt + 1;
}