#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int ml = 1;
        cin >> a >> b;
        for (int j = 0; j < b; j++)
        {
            ml *= a;
            ml %= 10;
        }
        if (ml == 0)
            cout << 10 << "\n";
        else
            cout << ml << "\n";
    }
    return 0;
}