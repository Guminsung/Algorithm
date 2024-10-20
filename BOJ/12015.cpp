#include <iostream>
#include <vector>
using namespace std;
void LIS(int n);
void BS(int s, int e, int v);
int v[1000000];
vector<int> DP;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    LIS(n);
    cout << DP.size();
    return 0;
}

void LIS(int n)
{
    DP.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (DP[DP.size() - 1] < v[i])
            DP.push_back(v[i]);
        else
            BS(0, DP.size() - 1, v[i]);
    }
}

void BS(int s, int e, int v)
{
    if (s == e)
        DP[s] = v;
    else
    {
        int m = (s + e) / 2;
        if (DP[m] >= v)
            BS(s, m, v);
        else
            BS(m + 1, e, v);
    }
}