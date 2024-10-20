#include <iostream>
#include <algorithm>
using namespace std;
int v[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, x, num, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    sort(v, v + n);
    cin >> x;
    int s = 0, e = n - 1;
    while (s < e)
    {
        if (v[s] + v[e] < x)
            s++;
        else if (v[s] + v[e] > x)
            e--;
        else
        {
            cnt++;
            s++;
        }
    }
    cout << cnt;
    return 0;
}