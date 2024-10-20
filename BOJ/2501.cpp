#include <iostream>
using namespace std;

int main()
{
    int i, n, k, c = 0;
    cin >> n >> k;
    for (i = 1; i <= n; i++)
    {
        if (n % i == 0)
            c++;
        if (c == k)
            break;
    }
    if (c != k)
        i = 0;
    cout << i;
    return 0;
}