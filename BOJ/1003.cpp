#include <iostream>
using namespace std;
int fibonacci_Z(int n);
int fibonacci_O(int n);
int DP_Z[41], DP_O[41];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        cout << fibonacci_Z(num) << " " << fibonacci_O(num) << "\n";
    }
    return 0;
}

int fibonacci_Z(int n)
{
    if (DP_Z[n] != 0)
        return DP_Z[n];
    if (n == 0)
    {
        DP_Z[0] = 1;
        return 1;
    }
    else if (n == 1)
        return 0;
    else
    {
        int temp = fibonacci_Z(n - 1) + fibonacci_Z(n - 2);
        DP_Z[n] = temp;
        return temp;
    }
}

int fibonacci_O(int n)
{
    if (DP_O[n] != 0)
        return DP_O[n];
    if (n == 0)
        return 0;
    else if (n == 1)
    {
        DP_O[1] = 1;
        return 1;
    }
    else
    {
        int temp = fibonacci_O(n - 1) + fibonacci_O(n - 2);
        DP_O[n] = temp;
        return temp;
    }
}