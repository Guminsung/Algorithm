#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sum = 0, d = 1000;
    cin >> n;
    for (int i = 0; i <= 3; i++)
    {
        sum += n / d;
        n %= d;
        d /= 10;
    }
    cout << sum;
    return 0;
}