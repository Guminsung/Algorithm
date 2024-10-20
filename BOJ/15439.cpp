#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, z;
    cin >> n;
    z = n * (n - 1);
    cout << z;
    return 0;
}