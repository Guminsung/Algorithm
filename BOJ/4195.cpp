#include <iostream>
#include <map>
#include <string>
using namespace std;
int parent(int x);
int v[200002], p[200002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, f;
    string s1, s2;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int i = 1; i <= 200001; i++)
        {
            v[i] = i;
            p[i] = 1;
        }
        map<string, int> m;
        int cnt = 1;
        cin >> f;
        for (int j = 0; j < f; j++)
        {
            cin >> s1 >> s2;
            if (m[s1] == 0)
                m[s1] = cnt++;
            if (m[s2] == 0)
                m[s2] = cnt++;
            int a = m[s1], b = m[s2];
            a = parent(a);
            b = parent(b);
            if (a < b)
            {
                v[b] = a;
                p[a] += p[b];
                cout << p[a] << "\n";
            }
            else if (b < a)
            {
                v[a] = b;
                p[b] += p[a];
                cout << p[b] << "\n";
            }
            else
                cout << p[a] << "\n";
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