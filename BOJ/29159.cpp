#include <iostream>
using namespace std;
int uclid(int x, int y);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    int x, y, m, A, B, A1, A2, B1, B2;
    for (int i = 0; i < 4; i++)
    {
        cin >> a >> b;
        x1 += a;
        y1 += b;
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> a >> b;
        x2 += a;
        y2 += b;
    }
    x = x2 - x1, y = y2 - y1;
    if (y % x == 0)
    {
        A = y / x;
        B = y1 / 4 - A * (x1 / 4);
        cout << A << " " << B;
    }
    else
    {
        int ax = abs(x), ay = abs(y);
        if (ax == x && ay == y || ax != x && ay != y)
        {
            m = uclid(ax, ay);
            A1 = ax / m;
            A2 = ay / m;
        }
        else
        {
            m = -uclid(ax, ay);
            A1 = ax / m;
            A2 = -ay / m;
            B = y1 / 4 * A1 - A2 * x1 / 4;
            m = uclid(A1, B);
        }
        cout << A2 << "/" << A1;
    }
    return 0;
}

int uclid(int x, int y)
{
    int big, small, temp;
    if (x > y)
        big = x, small = y;
    else
        big = y, small = x;
    while (big % small != 0)
    {
        temp = small;
        small = big - temp;
        big = temp;
    }
    return small;
}