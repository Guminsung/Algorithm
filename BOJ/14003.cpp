#include <iostream>
#include <vector>
using namespace std;
void LIS(int n);
void BS(int s, int e, int i);
pair<int, int> v[1000000];
int p[1000000];
vector<int> DP;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = make_pair(num, -1);
    }
    LIS(n);
    cout << DP.size() << "\n";
    int temp = DP[DP.size() - 1];
    p[cnt++] = v[temp].first;
    while (v[temp].second != -1)
    {
        temp = v[temp].second;
        p[cnt++] = v[temp].first;
    }
    for (int i = cnt - 1; i >= 0; i--)
        cout << p[i] << " ";
    return 0;
}

void LIS(int n)
{
    DP.push_back(0);
    for (int i = 1; i < n; i++)
    {
        if (v[DP[DP.size() - 1]].first < v[i].first)
        {
            v[i].second = DP[DP.size() - 1];
            DP.push_back(i); 
        }
        else
            BS(0, DP.size() - 1, i);
    }
}

void BS(int s, int e, int i)
{
    if (s == e)
    {
        if (s > 0)
            v[i].second = DP[s - 1];
        DP[s] = i;
    }
    else
    {
        int m = (s + e) / 2;
        if (v[DP[m]].first >= v[i].first)
            BS(s, m, i);
        else
            BS(m + 1, e, i);
    }
}