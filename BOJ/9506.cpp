#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    while (true)
    {
        cin >> n;
        if (n == -1)
            break;
        for (int i = 1; i < n; i++)
        {
            if (n % i == 0)
                sum += i;
        }
        if (sum == n)
        {
            cout << n << " = 1";
            for (int i = 2; i < n; i++)
            {
                if (n % i == 0)
                    cout << " + " << i;
            }
            cout << endl;
        }
        else
            cout << n << " is NOT perfect.\n";
        sum = 0;
    }
    return 0;
}