#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < t; i++)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            n ^= 6;
        }
        else
        {
            n *= 2;
            n ^= 6;
        }
    }
    cout << n;
    return 0;
}