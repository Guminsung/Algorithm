#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num, many, range, sum = 0, max = 0;
    double avg, result;
    vector<int> v;
    map<int, int> m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
        v.push_back(num);
        m[num]++;
    }
    sort(v.begin(), v.end());
    avg = (double)sum / n;
    result = round(avg);
    if (result == -0)
        result = 0;
    range = v[n - 1] - v[0];
    cout << result << "\n";
    cout << v[n / 2] << "\n";
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (m[v[i]] > max)
        {
            max = m[v[i]];
            many = v[i];
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != many && m[v[i]] == max)
        {
            many = v[i];
            break;
        }
    }
    cout << many << "\n";
    cout << range;
    return 0;
}