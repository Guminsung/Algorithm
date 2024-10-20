#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v;
    int n, k, num, c = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    while (k > 0)
    {
        if (v[v.size() - 1] > k)
            v.pop_back();
        else
        {
            c++;
            k -= v[v.size() - 1];
        }
    }
    cout << c;
    return 0;
}