#include <iostream>
using namespace std;

int main()
{
    int n, x, y, a, minx = 10000, maxx = -10000, miny = 10000, maxy = -10000;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        if (minx > x)
            minx = x;
        if (maxx < x)
            maxx = x;
        if (miny > y)
            miny = y;
        if (maxy < y)
            maxy = y;
    }
    if (n == 0)
        a = 0;
    else
        a = (maxx - minx) * (maxy - miny);
    cout << a;
    return 0;
}