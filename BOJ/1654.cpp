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
    int k, n, num;
    long long max = 0;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> num;
        v.push_back(num);
        if (num > max)
            max = num;
    }
    cout << PS(0, max, n);
    return 0;
}

int PS(int s, long long e, int n)
{
    if (s == e)
        return s;
    long long m = (s + e + 1) / 2;
    int c = 0;
    for (int i = 0; i < v.size(); i++)
        c += v[i] / m;
    if (c >= n)
        return PS(m, e, n);
    else
        return PS(s, m - 1, n);
}