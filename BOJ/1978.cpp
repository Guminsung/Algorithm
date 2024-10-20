#include <iostream>
using namespace std;

int main()
{
    int n, a, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        if (a == 1)
            continue;
        c++;
        for (int j = 2; j < a; j++)
        {
            if (a % j == 0)
            {
                c--;
                break;
            }
        }
    }
    cout << c;
    return 0;
}