#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int a, b, temp, min;
    cin >> a >> b;
    min = a * b;
    while (a != 1 && b != 1)
    {
        if (b > a)
        {
            temp = a;
            a = b;
            b = temp;
        }
        else if (a % b == 0)
        {
            min /= b;
            break;
        }
        else
            a = a % b;
    }
    cout << min;
    return 0;
}