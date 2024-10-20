#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b;
    char c;
    vector<tuple<int, int, char>> v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v.push_back(make_tuple(b, a, c));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << get<2>(v[i]);
    return 0;
}