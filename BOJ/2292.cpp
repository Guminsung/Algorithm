#include <iostream>
using namespace std;

int main()
{
    int n, r, c = 0, i = 1;
    cin >> n;
    r = (n - 2) / 6;
    r++;
    while (true)
    {
        c++;
        r = r - i;
        if (r <= 0)
            break;
        i++;
    }
    if (n == 1)
    {
        c = 0;
    }
    cout << c + 1;
    return 0;
}