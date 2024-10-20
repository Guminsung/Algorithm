#include <iostream>
using namespace std;
int v[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l, p, num, max = -1;
    cin >> n >> l >> p;
    for (int i = 0; i < p; i++)
    {
        cin >> num;
        if (num < l * n)
        {
            v[num / l + 1]++;
            if (num % l < l / 2 && max < l / 2 - num % l)
                max = l / 2 - num % l;
            else if (num % l >= l / 2 && max < num % l - l / 2)
                max = num % l - l / 2;
        }
        else
        {
            v[n]++;
            if (num - l * n + l / 2 > max)
                max = num - l * n + l / 2;
        }
    }
    cout << max << "\n";
    max = -1;
    for (int i = 1; i <= n; i++)
        if (max < v[i])
            max = v[i];
    cout << max;
    return 0;
}