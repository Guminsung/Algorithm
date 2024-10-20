#include <iostream>
using namespace std;
void BS(int s, int e, int n, int k);
int result;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    BS(1, k, n, k);
    cout << result;
    return 0;
}

void BS(int s, int e, int n, int k)
{
    if (s <= e)
    {
        int m = (s + e) / 2, c = 0;
        for (int i = 1; i <= n; i++)
        {
            if (m / i > n)
                c += n;
            else
                c += m / i;
        }
        if (c < k)
            BS(m + 1, e, n, k);
        else
        {
            result = m;
            BS(s, m - 1, n, k);
        }
    }
}