#include <iostream>
#include <algorithm>
using namespace std;
int v[199];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    sort(v, v + n);
    cout << v[n / 2];
    return 0;
}