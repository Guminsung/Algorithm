#include <iostream>
using namespace std;

int main()
{
    int m, n, min = 10000, sum = 0;
    cin >> m >> n;
    for (int i = m; i <= n; i++)
    {
        if (i == 1)
            continue;
        sum += i;
        if (min > i)
            min = i;
        for (int j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                sum -= i;
                if (min == i)
                    min = 10000;
                break;
            }
        }
    }
    if (sum == 0)
        cout << "-1";
    else
        cout << sum << endl
             << min;
    return 0;
}