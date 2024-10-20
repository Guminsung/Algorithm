#include <iostream>
using namespace std;

int main()
{
    int x, a, b, c, z = 0;
    cin >> x;
    c = x;
    for (int i = 1; i <= x; i++)
    {
        if (c == 0)
            break;
        z++;
        for (int j = 1; j <= i; j++)
        {
            a = i - j + 1;
            b = j;
            c--;
            if (c == 0)
                break;
        }
    }
    if (z % 2 != 0)
    {
        cout << a << "/" << b;
    }
    else
    {
        cout << b << "/" << a;
    }
    return 0;
}