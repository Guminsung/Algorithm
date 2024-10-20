#include <iostream>
using namespace std;

int main()
{
    int n, sum;
    cin >> n;
    for (int k = 1; k <= n; k++)
    {
        int i = k;
        sum = i + i / 100000;
        i = i % 100000;
        sum += i / 10000;
        i = i % 10000;
        sum += i / 1000;
        i = i % 1000;
        sum += i / 100;
        i = i % 100;
        sum += i / 10;
        i = i % 10;
        sum += i;
        if (sum == n)
        {
            cout << k;
            break;
        }
        if (k == n)
        {
            cout << "0";
        }
    }
    return 0;
}