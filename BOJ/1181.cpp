#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cp(string a, string b)
{
    if (a.size() == b.size())
        return a < b;
    else
        return a.size() < b.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cp);
    v.erase(unique(v.begin(),v.end()),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}