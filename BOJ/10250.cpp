#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, h, w, n, f, b;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> h >> w >> n;
        b = (n - 1) / h + 1;
        f = n % h;
        if (n % h == 0)
            f = h;
        if (b < 10)
            cout << f << '0' << b;
        else
            cout << f << b;
        cout << "\n";
    }
    return 0;
}