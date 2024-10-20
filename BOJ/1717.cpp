#include <iostream>
using namespace std;
int parent(int x);
int v[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        v[i] = i;
    for (int i = 0; i < m; i++)
    {
        cin >> q >> a >> b;
        if (q == 0)
        {
            a = parent(a);
            b = parent(b);
            if (a < b)
                v[b] = a;
            else
                v[a] = b;
        }
        else
        {
            a = parent(a);
            b = parent(b);
            if (a == b)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
    return 0;
}

int parent(int x)
{
    if (v[x] == x)
        return x;
    return v[x] = parent(v[x]);
}