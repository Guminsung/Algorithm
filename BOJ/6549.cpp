#include <iostream>
using namespace std;
long long Area(int l, int r);
int v[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    int num;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v[i] = num;
        }
        cout << Area(0, n) << "\n";
    }
    return 0;
}

long long Area(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2, a = 1, b = 1;
        long long left, right, area = v[m], height = v[m], max = -1;
        left = Area(l, m);
        right = Area(m + 1, r);
        if (left > right)
            max = left;
        else
            max = right;
        while (((m - a) >= l) || ((m + b) < r))
        {
            if (m - a < l)
            {
                if (v[m + b] < height)
                    height = v[m + b];
                if (area < (a + b) * height)
                    area = (a + b) * height;
                b++;
            }
            else if (m + b >= r)
            {
                if (v[m - a] < height)
                    height = v[m - a];
                if (area < (a + b) * height)
                    area = (a + b) * height;
                a++;
            }
            else if (v[m - a] > v[m + b])
            {
                if (v[m - a] < height)
                    height = v[m - a];
                if (area < (a + b) * height)
                    area = (a + b) * height;
                a++;
            }
            else
            {
                if (v[m + b] < height)
                    height = v[m + b];
                if (area < (a + b) * height)
                    area = (a + b) * height;
                b++;
            }
        }
        if (max < area)
            max = area;
        return max;
    }
    else
        return 0;
}