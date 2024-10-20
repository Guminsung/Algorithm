#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, d, t, sum = 0;
    bool imp = true;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d >> t;
        v.push_back(make_pair(d, t));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " ";
        int temp = v[i].first / 6 + v[i].first / 7;
        sum += v[i].second;
        if (sum > 2 * v[i].first - temp)
        {
            imp = false;
            break;
        }
    }
    if (imp == false)
        cout << -1;
    else
    {
        int lst = v[v.size() - 1].first, temp = lst / 6 + lst / 7;
        cout << sum - lst - temp;
    }
    return 0;
}