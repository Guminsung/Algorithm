#include <iostream>
#include <vector>
using namespace std;
int PS(int s, long long e, int n);
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, num;
    long long max = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
        if (num > max)
            max = num;
    }
    cout << PS(0, max, m);
    return 0;
}

int PS(int s, long long e, int n)
{
    if (s == e)
        return s;
    long long m = (s + e + 1) / 2;
    long long c = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i] > m)
            c += v[i] - m;
    if (c >= n)
        return PS(m, e, n);
    else
        return PS(s, m - 1, n);
}