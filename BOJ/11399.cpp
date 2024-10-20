#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, sum = 0, f_sum = 0;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        f_sum += sum;
    }
    cout << f_sum;
    return 0;
}