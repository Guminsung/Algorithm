#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int v[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, m, n, num;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        queue<int> q;
        vector<int> b;
        int cnt = 0;
        cin >> n >> m;
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            v[j] = num;
            b.push_back(num);
            q.push(j);
        }
        sort(b.begin(), b.end());
        while (q.size() > 0)
        {
            int temp = q.front();
            q.pop();
            if (v[temp] < b[b.size() - 1])
                q.push(temp);
            else
            {
                if (temp == m)
                {
                    cout << cnt + 1 << "\n";
                    b.pop_back();
                }
                else
                {
                    cnt++;
                    b.pop_back();
                }
            }
        }
    }
    return 0;
}