#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v, v2;
    unordered_map<int, int> h;
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
        v2.push_back(num);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        h[v[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        v2[i] = h.find(v2[i])->second;
    }
    for (int i = 0; i < n; i++)
    {
        cout << v2[i] << " ";
    }
    return 0;
}