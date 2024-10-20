#include <iostream>
using namespace std;
void DC(int n, int r, int c);
int sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, r, c;
    cin >> n >> r >> c;
    DC(1, r, c);
    cout << sum;
    return 0;
}

void DC(int n, int r, int c)
{
    int temp = 1;
    if (r > 0)
    {
        if (r % 2 == 1)
        {
            for (int i = 0; i < 2 * n - 1; i++)
                temp *= 2;
            sum += temp;
        }
    }
    temp = 1;
    if (c > 0)
    {

        if (c % 2 == 1)
        {
            for (int i = 0; i < 2 * (n - 1); i++)
                temp *= 2;
            sum += temp;
        }
    }
    if (r > 0 || c > 0)
        DC(n + 1, r / 2, c / 2);
}