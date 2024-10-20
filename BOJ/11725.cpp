#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> v(100001);
int tree[100001];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    q.push(1);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (int i = 0; i < v[temp].size(); i++)
            if (tree[v[temp][i]] == 0)
            {
                tree[v[temp][i]] = temp;
                q.push(v[temp][i]);
            }
    }
    for (int i = 2; i <= n; i++)
        cout << tree[i] << "\n";
    return 0;
}