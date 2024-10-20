#include <iostream>
#include <queue>
using namespace std;
char bomb[300][300];
bool check[300][300];
bool bc(int x, int y, int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n;
    string s;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        queue<pair<int, int>> q;
        int cnt = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> s;
            for (int k = 0; k < s.size(); k++)
                bomb[j][k] = s[k];
        }
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if (bomb[j][k] == '*')
                    check[j][k] = true;
                else if (check[j][k] == false)
                {
                    if (bc(j, k, n) == true)
                    {
                        cnt++;
                        q.push(make_pair(j, k));
                        while (q.size() > 0)
                        {
                            int x = q.front().first, y = q.front().second;
                            q.pop();
                            if (bc(x, y, n) == true)
                            {
                                for (int a = -1; a <= 1; a++)
                                    for (int b = -1; b <= 1; b++)
                                        if (x + a >= 0 && y + b >= 0 && x + a < n && y + b < n)
                                            if (check[x + a][y + b] == false)
                                            {
                                                check[x + a][y + b] = true;
                                                q.push(make_pair(x + a, y + b));
                                            }
                            }
                        }
                    }
                }
            }
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (check[j][k] == false)
                    cnt++;
                else
                    check[j][k] = false;
        cout << "#" << i << " " << cnt << "\n";
    }
    return 0;
}

bool bc(int x, int y, int n)
{
    for (int a = -1; a <= 1; a++)
        for (int b = -1; b <= 1; b++)
            if (x + a >= 0 && y + b >= 0 && x + a < n && y + b < n && bomb[x + a][y + b] == '*')
                return false;
    return true;
}