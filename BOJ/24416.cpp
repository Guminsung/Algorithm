#include <iostream>
using namespace std;
int fib(int n);
int fibonacci(int n);
int f[40];
int c1 = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    fib(n);
    cout << c1 << " " << fibonacci(n);
    return 0;
}

int fib(int n)
{
    if (n == 1 || n == 2)
    {
        c1++;
        return 1;
    }
    else
        return fib(n - 1) + fib(n - 2);
}

int fibonacci(int n)
{
    int c2 = 0;
    f[1] = 1, f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
        c2++;
    }
    return c2;
}