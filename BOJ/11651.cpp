#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> v2;
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> v1;
        cin >> x >> y;
        v1.push_back(y);
        v1.push_back(x);
        v2.push_back(v1);
    }
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; i++)
    {
        cout << v2[i][1] << " " << v2[i][0] << "\n";
    }
    return 0;
}