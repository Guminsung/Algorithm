#include <iostream>
using namespace std;
int fibonacci(int n);
int v[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}

int fibonacci(int n)
{
    v[0] = 1, v[1] = 2;
    for (int i = 2; i < n; i++)
    {
        v[i] = v[i - 1] + v[i - 2];
        v[i] %= 15746;
    }
    return v[n - 1];
}
