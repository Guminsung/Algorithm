#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        while (1)
        {
            if (num % 5 == 0)
            {
                c++;
                num /= 5;
            }
            else
                break;
        }
    }
    cout << c;
    return 0;
}