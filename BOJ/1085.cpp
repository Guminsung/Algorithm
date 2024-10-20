#include <iostream>
using namespace std;

int main()
{
    int x, y, w, h, min, min2;
    cin >> x >> y >> w >> h;
    if (x < w - x)
        min = x;
    else
        min = w - x;
    if (y < h - y)
        min2 = y;
    else
        min2 = h - y;
    if (min < min2)
        cout << min;
    else
        cout << min2;
    return 0;
}