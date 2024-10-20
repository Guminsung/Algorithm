#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s;
    vector<string> v;
    unordered_map<string, string> h;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        h[s] = s;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (h[s] == s)
            v.push_back(s);
    }
    sort(v.begin(),v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}