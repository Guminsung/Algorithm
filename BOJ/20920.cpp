#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, int> h;

bool compare(string a, string b)
{
    if (a.size() == b.size() && h[a] == h[b])
        return a < b;
    else if (h[a] == h[b])
        return a.size() > b.size();
    return h[a] > h[b];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string s;
    vector<string> v;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s.size() >= m)
        {
            v.push_back(s);
            h[s]++;
        }
    }
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}