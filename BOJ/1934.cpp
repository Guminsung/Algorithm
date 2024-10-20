#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, a, b, num, max;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        max = 1;
        cin >> a >> b;
        for (int j = 45000; j >= 1; j--)
        {
            if (a % j == 0 && b % j == 0)
            {
                max = j;
                break;
            }
        }
        num = a * b / max;
        cout << num << "\n";
    }
    return 0;
}