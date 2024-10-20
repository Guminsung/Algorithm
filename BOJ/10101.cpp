#include <iostream>
using namespace std;

int main()
{
    int a, b, c, sum;
    cin >> a >> b >> c;
    sum = a + b + c;
    if (sum != 180)
        cout << "Error";
    else
    {
        if (a == b && b == c)
            cout << "Equilateral";
        else if (a == b || b == c || a == c)
            cout << "Isosceles";
        else
            cout << "Scalene";
    }
    return 0;
}