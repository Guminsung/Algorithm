#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    char c;
    int a = 0, b = 0;
    while (1)
    {
        int n;
        cin >> c;
        if (c == '\0')
            continue;
        if (c == '#')
            break;
        else if (c == '*')
        {
            if (a > b)
                cout << "Cheryl" << "\n";
            else if (a < b)
                cout << "Tania" << "\n";
            else
                cout << "Draw" << "\n";
            a = 0, b = 0;
        }
        else
        {
            if (c == '1')
            {
                cin >> c;
                n = 10;
            }
            else
                n = c - '0';
            if (n % 2 == 1)
                a++;
            else
                b++;
        }
    }
    return 0;
}