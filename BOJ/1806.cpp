#include <iostream>
using namespace std;
int v[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, s, num, sum, len = 100001;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    int a = 0, b = 0;
    sum = v[a];
    while (b < n)
    {
        if (a == b)
        {
            if (sum < s)
            {
                b++;
                sum += v[b];
            }
            else
            {
                len = 1;
                break;
            }
        }
        else
        {
            if (sum < s)
            {
                b++;
                sum += v[b];
            }
            else
            {
                if (len > b - a + 1)
                    len = b - a + 1;
                sum -= v[a];
                a++;
            }
        }
    }
    if (len == 100001)
        cout << 0;
    else
        cout << len;
    return 0;
}