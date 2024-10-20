#include <iostream>
#include <algorithm>
using namespace std;
int v[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, zero = 2000000001;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    sort(v, v + n);
    int s = 0, e = n - 1, left, right;
    while (s < e)
    {
        if (v[s] + v[e] < 0)
        {
            if (-(v[s] + v[e]) < zero)
            {
                left = s;
                right = e;
                zero = -v[s] - v[e];
            }
            s++;
        }
        else if (v[s] + v[e] >= 0)
        {
            if (v[s] + v[e] < zero)
            {
                left = s;
                right = e;
                zero = v[s] + v[e];
            }
            e--;
        }
    }
    cout << v[left] << " " << v[right];
    return 0;
}