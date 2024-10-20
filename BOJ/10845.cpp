#include <iostream>
using namespace std;
int v[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, c = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> num;
            v[c++] = num;
        }
        else if (s == "pop")
        {
            if (c == 0)
                cout << -1 << "\n";
            else
            {
                cout << v[0] << "\n";
                for (int j = 1; j < c; j++)
                    v[j - 1] = v[j];
                c--;
            }
        }
        else if (s == "size")
            cout << c << "\n";
        else if (s == "empty")
        {
            if (c == 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (s == "front")
        {
            if (c == 0)
                cout << -1 << "\n";
            else
                cout << v[0] << "\n";
        }
        else if (s == "back")
        {
            if (c == 0)
                cout << -1 << "\n";
            else
                cout << v[c - 1] << "\n";
        }
    }
    return 0;
}