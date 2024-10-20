#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l;
    long r = 1, sum = 0;
    char c;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> c;
        sum += ((int)c - 96) * r;
        sum %= 1234567891;
        r *= 31;
        r %= 1234567891;
    }
    cout << sum;
    return 0;
}