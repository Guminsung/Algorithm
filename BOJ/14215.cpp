#include <iostream>
using namespace std;

int main()
{
    int a, b, c, sum = 0, max;
    cin >> a >> b >> c;
    max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    sum = a + b + c;
    while (true)
    {
        if ((sum / max) < 2 || sum == max * 2)
        {
            sum--;
            max--;
        }
        else
            break;
    }
    cout << sum;
    return 0;
}