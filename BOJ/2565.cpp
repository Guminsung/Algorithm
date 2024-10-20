#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Electric_line(int n);
vector<pair<int, int>> v;
int DP[100];

int main()
{
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    cout << Electric_line(n);
    return 0;
}

int Electric_line(int n)
{
    for (int i = 0; i < n; i++)
    {
        DP[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i].second > v[j].second)
                if (DP[i] < DP[j] + 1)
                    DP[i] = DP[j] + 1;
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < DP[i])
            max = DP[i];
    }
    return n - max;
}