#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, z = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        z *= i;
    }
    cout << z;
    return 0;
}