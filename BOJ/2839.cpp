#include <iostream>
using namespace std;

int main()
{
    int n, c = 0;
    cin >> n;
    while (n != 1 && n != 2 && n != 4)
    {
        if (n % 3 == 0 && n < 15)
        {
            c += n / 3;
            break;
        }
        if (n >= 5)
        {
            n = n - 5;
            c++;
        }
    }
    if (n == 1 || n == 2 || n == 4)
        c = -1;
    cout << c;
    return 0;
}