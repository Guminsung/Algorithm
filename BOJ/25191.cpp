#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, cnt = 0;
    cin >> n >> a >> b;
    if (n - b >= 0)
    {
        cnt += b;
        n -= b;
    }
    else
    {
        cnt += n;
        n = 0;
    }
    if (n - a / 2 >= 0)
    {
        cnt += a / 2;
        n -= a / 2;
    }
    else
        cnt += n;
    cout << cnt;
    return 0;
}