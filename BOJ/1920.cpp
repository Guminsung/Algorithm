#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int BS(int s, int e, int num);
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        cout << BS(0, v.size() - 1, num) << "\n";
    }
    return 0;
}

int BS(int s, int e, int num)
{
    if (s > e)
        return 0;
    else
    {
        int middle = (s + e) / 2;
        if (v[middle] == num)
            return 1;
        else if (v[middle] > num)
            return BS(s, middle - 1, num);
        else
            return BS(middle + 1, e, num);
    }
}