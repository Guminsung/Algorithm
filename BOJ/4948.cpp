#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n, c;
    bool f;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        c = 0;
        m = 2 * n;
        n++;
        while (n <= m)
        {
            f = true;
            for (int j = 2; j * j <= n; j++)
            {
                if (n % j == 0)
                {
                    f = false;
                    break;
                }
            }
            if (f == true && n != 1)
            {
                c++;
            }
            n++;
        }
        cout << c << "\n";
    }
    return 0;
}