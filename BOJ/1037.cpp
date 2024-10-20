#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a;
    int v[50];
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> v[i];
    }
    sort(v, v + a);
    n = v[0] * v[a - 1];
    cout << n;
    return 0;
}