#include <iostream>
#include <vector>
using namespace std;
void dfs(int s, int sum);
vector<vector<pair<int, int>>> v(100001);
int visited[100001];
int Max = -1;
int index;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, temp, num, cost;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        while (1)
        {
            cin >> num;
            if (num == -1)
                break;
            cin >> cost;
            v[temp].push_back(make_pair(num, cost));
        }
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    Max = -1;
    dfs(index, 0);
    cout << Max;
    return 0;
}

void dfs(int s, int sum)
{
    if (sum > Max)
    {
        Max = sum;
        index = s;
    }
    visited[s] = true;
    for (int i = 0; i < v[s].size(); i++)
        if (visited[v[s][i].first] == false)
            dfs(v[s][i].first, sum + v[s][i].second);
}