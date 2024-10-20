#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (sqrtl(num) != (int)(sqrtl(num)))
            cout << 0 << " ";
        else
            cout << 1 << " ";
    }
    return 0;
}