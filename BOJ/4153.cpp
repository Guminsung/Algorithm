#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, temp;
    while (1)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        if (a < b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if (a < c)
        {
            temp = a;
            a = c;
            c = temp;
        }
        if (a * a == b * b + c * c)
            cout << "right"
                 << "\n";
        else
            cout << "wrong"
                 << "\n";
    }
    return 0;
}