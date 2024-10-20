#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, cnt = 0;
    cin >> a >> b;
    while (b > a)
    {
        if (b % 2 == 0)
        {
            b /= 2;
            cnt++;
        }
        else if (b % 10 == 1)
        {
            b /= 10;
            cnt++;
        }
        else
            break;
    }
    if (b == a)
        cout << cnt + 1;
    else
        cout << -1;
    return 0;
}