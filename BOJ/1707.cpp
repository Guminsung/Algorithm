#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, v, e, a, b;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        vector<vector<int>> p(20001);
        queue<pair<int, int>> q;
        int color[20001] = {0};
        bool yon = true;
        cin >> v >> e;
        for (int j = 0; j < e; j++)
        {
            cin >> a >> b;
            p[a].push_back(b);
            p[b].push_back(a);
        }
        for (int j = 1; j <= v; j++)
            if (color[j] == 0)
            {
                q.push(make_pair(j, 1));
                color[1] = 1;
                while (q.size() > 0)
                {
                    int temp = q.front().first, c = q.front().second;
                    q.pop();
                    for (int j = 0; j < p[temp].size(); j++)
                    {
                        if (color[p[temp][j]] == 0)
                            if (c == 1)
                            {
                                color[p[temp][j]] = 2;
                                q.push(make_pair(p[temp][j], 2));
                            }
                            else
                            {
                                color[p[temp][j]] = 1;
                                q.push(make_pair(p[temp][j], 1));
                            }
                        else if (color[p[temp][j]] == c)
                            yon = false;
                    }
                    if (yon == false)
                        break;
                }
            }
        if (yon == true)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
        for (int j = 1; j <= v; j++)
            while (p[j].size() > 0)
                p[j].pop_back();
        while (q.size() > 0)
            q.pop();
    }
    return 0;
}