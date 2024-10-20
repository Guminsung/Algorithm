#include <iostream>
using namespace std;
void Mul(int n, long long m, int c);
long long sum = 1;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    Mul(b, a, c);
    cout << sum;
    return 0;
}

void Mul(int n, long long m, int c)
{
    if (n > 0)
    {
        long long mul = m % c;
        if (n % 2 == 1)
        {
            sum *= mul;
            sum %= c;
        }
        Mul(n / 2, mul * mul, c);
    }
}