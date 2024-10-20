#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a1, b1, a2, b2, a, b, fb1, fb2, fa, fb, temp;
    cin >> a1 >> b1 >> a2 >> b2;
    fb1 = b1;
    fb2 = b2;
    a = a1 * fb2 + a2 * fb1;
    b = fb1 * fb2;
    while (b1 != 1 && b2 != 1)
    {
        if (b1 > b2)
        {
            if (b1 % b2 == 0)
            {
                a = (a1 * fb2 + a2 * fb1) / b2;
                b = fb1 * fb2 / b2;
                break;
            }
            else
                b1 = b1 % b2;
        }
        else if (b2 % b1 == 0)
        {
            a = (a1 * fb2 + a2 * fb1) / b1;
            b = fb1 * fb2 / b1;
            break;
        }
        else
            b2 = b2 % b1;
    }
    fa = a;
    fb = b;
    while (a != 1 && b != 1)
    {
        if (a > b)
        {
            if (a % b == 0)
            {
                fa /= b;
                fb /= b;
                break;
            }
            else
                a = a % b;
        }
        else if (b % a == 0)
        {
            fa /= a;
            fb /= a;
            break;
        }
        else
            b = b % a;
    }
    cout << fa << " " << fb;
    return 0;
}