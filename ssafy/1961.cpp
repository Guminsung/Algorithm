#include <iostream>
using namespace std;
int v[7][7];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, n, num;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                cin >> num;
                v[j][k] = num;
            }
        cout << "#" << i << "\n";
        for (int k = 0; k < n; k++)
        {
            for (int j = n - 1; j >= 0; j--)
                cout << v[j][k];
            cout << " ";
            for (int j = n - 1; j >= 0; j--)
                cout << v[n - k - 1][j];
            cout << " ";
            for (int j = 0; j < n; j++)
                cout << v[j][n - k - 1];
            cout << "\n";
        }
    }
    return 0;
}