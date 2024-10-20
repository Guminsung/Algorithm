#include <iostream>
using namespace std;
int makeone(int n);
int DP[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cout << makeone(n);
    return 0;
}

int makeone(int n)
{
    if (n == 1)
        return 0;
    if (DP[n] != 0)
        return DP[n];
    else if (n == 2 || n == 3)
        return 1;
    else
    {
        DP[n] = makeone(n - 1) + 1;
        if (n % 2 == 0)
        {
            int temp = makeone(n / 2) + 1;
            if (DP[n] > temp)
                DP[n] = temp;
        }
        if (n % 3 == 0)
        {
            int temp = makeone(n / 3) + 1;
            if (DP[n] > temp)
                DP[n] = temp;
        }
        return DP[n];
    }
}