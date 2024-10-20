#include <iostream>
using namespace std;
int stack[10000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, c = -1;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> num;
            stack[++c] = num;
        }
        else if (s == "pop")
        {
            if (c == -1)
                cout << -1 << "\n";
            else
                cout << stack[c--] << "\n";
        }
        else if (s == "size")
            cout << c + 1 << "\n";
        else if (s == "empty")
        {
            if (c == -1)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (s == "top")
        {
            if (c == -1)
                cout << -1 << "\n";
            else
                cout << stack[c] << "\n";
        }
    }
    return 0;
}