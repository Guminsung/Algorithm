#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, z = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        z *= 2;
    }
    cout << z;
    return 0;
}