#include <iostream>
using namespace std;

void back_tracking(int n, int c, int m);

int stack[9];

int main()
{
    int n, m;
    cin >> n >> m;
    back_tracking(n, 1, m);
    return 0;
}

void back_tracking(int n, int c, int m)
{
    if (c <= m)
    {
        for (int i = 1; i <= n; i++)
        {
            stack[c] = i;
            back_tracking(n, c + 1, m);
        }
    }
    else
    {
        for (int i = 1; i < c; i++)
            cout << stack[i] << " ";
        cout << "\n";
    }
}