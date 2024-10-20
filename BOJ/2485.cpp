#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, a, b, max, c = 0;
    int v1[100000], v2[100000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        v2[i] = v1[i + 1] - v1[i];
    }
    max = v2[0];
    for (int i = 1; i < n - 1; i++)
    {
        a = max;
        b = v2[i];
        while (a != 1 && b != 1)
        {
            if (a > b)
            {
                if (a % b == 0)
                {
                    max = b;
                    break;
                }
                else
                    a = a % b;
            }
            else if (b % a == 0)
            {
                max = a;
                break;
            }
            else
                b = b % a;
        }
        if (a == 1 || b == 1)
            max = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        c += v2[i] / max - 1;
    }
    cout << c;
    return 0;
}