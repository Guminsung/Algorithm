#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c = 0;
    cin >> n;
    for (int i = 1; i * i <= n; i++)
    {
        c++;
    }
    cout << c;
    return 0;
}