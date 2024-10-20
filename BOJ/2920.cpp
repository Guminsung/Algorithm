#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (n == 1)
        for (int i = 2; i <= 8; i++)
        {
            cin >> n;
            if (i == 8)
            {
                cout << "ascending";
                break;
            }
            if (n == i)
                continue;
            else
            {
                cout << "mixed";
                break;
            }
        }
    else if (n == 8)
        for (int i = 2; i <= 8; i++)
        {
            cin >> n;
            if (i == 8)
            {
                cout << "descending";
                break;
            }
            if (n == 9 - i)
                continue;
            else
            {
                cout << "mixed";
                break;
            }
        }
    else
        cout << "mixed";
    return 0;
}