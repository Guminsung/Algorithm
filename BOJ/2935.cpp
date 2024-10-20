#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a, b;
    char c;
    cin >> a >> c >> b;
    if (c == '*')
    {
        cout << "1";
        for (int i = 0; i < (a.size() - 1) + (b.size() - 1); i++)
            cout << "0";
    }
    else
    {
        int max;
        if (a.size() >= b.size())
        {
            a[a.size() - b.size()] += 1;
            cout << a;
        }
        else if (a.size() < b.size())
        {
            b[b.size() - a.size()] += 1;
            cout << b;
        }
    }
    return 0;
}