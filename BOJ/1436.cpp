#include <iostream>
using namespace std;

int main()
{
    int n, num, a, b, c, d, e, f, g, count = 0;
    cin >> n;
    for (int i = 1; i < 10000000; i++)
    {
        num = i;
        a = num / 1000000;
        num = num % 1000000;
        b = num / 100000;
        num = num % 100000;
        c = num / 10000;
        num = num % 10000;
        d = num / 1000;
        num = num % 1000;
        e = num / 100;
        num = num % 100;
        f = num / 10;
        g = num % 10;
        if (a == 6 && b == 6 && c == 6 || b == 6 && c == 6 && d == 6 || c == 6 && d == 6 && e == 6 || d == 6 && e == 6 && f == 6 || e == 6 && f == 6 && g == 6)
            count++;
        if (n == count)
        {
            cout << i;
            break;
        }
    }
    return 0;
}