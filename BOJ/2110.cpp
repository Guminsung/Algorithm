#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int PS(int s, int e, int n);
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c, num;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cout << PS(1, v[v.size() - 1] - v[0], c);
    return 0;
}

int PS(int s, int e, int n)
{
    if (s == e)
        return s;
    int m = (s + e + 1) / 2, c = 1, temp = v[0];
    for (int i = 0; i < v.size(); i++)
        if (v[i] - temp >= m)
        {
            c++;
            temp = v[i];
        }
    if (c >= n)
        return PS(m, e, n);
    else
        return PS(s, m - 1, n);
}