#include <iostream>
using namespace std;

int main()
{
    int a, b, c, sum = 0, max;
    while (true)
    {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            break;
        max = a;
        if (max < b)
            max = b;
        if (max < c)
            max = c;
        sum = a + b + c;
        if ((sum / max) < 2 || sum == max * 2)
            cout << "Invalid" << endl;
        else
        {
            if (a == b && b == c)
                cout << "Equilateral" << endl;
            else if (a == b || b == c || a == c)
                cout << "Isosceles" << endl;
            else
                cout << "Scalene" << endl;
        }
    }
    return 0;
}