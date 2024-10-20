#include <iostream>
using namespace std;
pair<int, int> p[36];
bool visited[6][6];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char c;
    int n;
    bool value = true;
    for (int i = 0; i < 36; i++)
    {
        cin >> c >> n;
        p[i].first = (int)c - 65;
        p[i].second = (int)n - 1;
    }
    visited[p[0].first][p[0].second] = true;
    for (int i = 1; i < 36; i++)
    {
        if (visited[p[i].first][p[i].second] == false)
            if (abs(p[i].first - p[i - 1].first) == 1 && abs(p[i].second - p[i - 1].second) == 2)
                visited[p[i].first][p[i].second] = true;
            else if (abs(p[i].first - p[i - 1].first) == 2 && abs(p[i].second - p[i - 1].second) == 1)
                visited[p[i].first][p[i].second] = true;
            else
            {
                value = false;
                break;
            }
        else
        {
            value = false;
            break;
        }
        if (i == 35)
        {
            if (abs(p[i].first - p[0].first) == 1 && abs(p[i].second - p[0].second) == 2)
                continue;
            else if (abs(p[i].first - p[0].first) == 2 && abs(p[i].second - p[0].second) == 1)
                continue;
            else
            {
                value = false;
                break;
            }
        }
    }
    if (value == true)
        cout << "Valid";
    else
        cout << "Invalid";
    return 0;
}