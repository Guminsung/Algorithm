#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> k;
        while (k % 2 == 0 && k != 1)
            k /= 2;
        if (k == 1)
            cout << "GoHanGang" << "\n";
        else
            cout << "Gazua" << "\n";
    }
    return 0;
}