#include <iostream>
using namespace std;
void DC(int x, int y, int n);
int v[2187][2187];
int Minus = 0, Zero = 0, Plus = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            v[i][j] = num;
        }
    DC(0, 0, n);
    cout << Minus << "\n"
         << Zero << "\n"
         << Plus;
    return 0;
}

void DC(int x, int y, int n)
{
    int temp = v[x][y];
    bool stop = true;
    for (int i = x; i < x + n; i++)
    {
        if (stop == false)
            break;
        for (int j = y; j < y + n; j++)
        {
            if (temp != v[i][j])
            {
                DC(x, y, n / 3);
                DC(x + (n / 3), y, n / 3);
                DC(x + 2 * (n / 3), y, n / 3);
                DC(x, y + (n / 3), n / 3);
                DC(x + (n / 3), y + (n / 3), n / 3);
                DC(x + 2 * (n / 3), y + (n / 3), n / 3);
                DC(x, y + 2 * (n / 3), n / 3);
                DC(x + (n / 3), y + 2 * (n / 3), n / 3);
                DC(x + 2 * (n / 3), y + 2 * (n / 3), n / 3);
                stop = false;
                break;
            }
            if (i == x + n - 1 && j == y + n - 1)
            {
                if (temp == -1)
                    Minus++;
                else if (temp == 0)
                    Zero++;
                else
                    Plus++;
            }
        }
    }
}