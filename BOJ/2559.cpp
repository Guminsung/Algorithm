#include <iostream>
using namespace std;
int v[100001];
int PS[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, num, max = -10000001;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    for (int i = 1; i <= n; i++)
        PS[i] = PS[i - 1] + v[i];
    for (int i = k; i <= n; i++)
        if (max < PS[i] - PS[i - k])
            max = PS[i] - PS[i - k];
    cout << max;
    return 0;
}