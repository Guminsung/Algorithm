#include <iostream>
using namespace std;

void star(int r, int c, int m);

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            star(i, j, n / 3);
        cout << "\n";
    }
    return 0;
}

void star(int r, int c, int m)
{
    if ((r / m) % 3 == 1 && (c / m) % 3 == 1)
        cout << " ";
    else
    {
        if (m == 1)
            cout << "*";
        else
            star(r, c, m / 3);
    }
}