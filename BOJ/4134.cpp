#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, num;
    bool f;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        cin >> n;
        while (true)
        {
            f = true;
            for (long long j = 2; j * j <= n; j++)
            {
                if (n % j == 0)
                {
                    f = false;
                    break;
                }
            }
            if (f == true && n != 0 && n != 1)
            {
                cout << n << "\n";
                break;
            }
            n++;
        }
    }
    return 0;
}