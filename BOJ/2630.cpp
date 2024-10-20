#include <iostream>
using namespace std;
void DC(int x1, int x2, int y1, int y2);
int v[128][128];
int black = 0, white = 0;

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
    DC(0, n, 0, n);
    cout << white << "\n"
         << black;
    return 0;
}

void DC(int x1, int x2, int y1, int y2)
{
    int temp = v[x1][y1];
    bool stop = true;
    for (int i = x1; i < x2; i++)
    {
        if (stop == false)
            break;
        for (int j = y1; j < y2; j++)
        {
            if (temp != v[i][j])
            {
                DC(x1, (x1 + x2) / 2, y1, (y1 + y2) / 2);
                DC((x1 + x2) / 2, x2, y1, (y1 + y2) / 2);
                DC(x1, (x1 + x2) / 2, (y1 + y2) / 2, y2);
                DC((x1 + x2) / 2, x2, (y1 + y2) / 2, y2);
                stop = false;
                break;
            }
            if (i == x2 - 1 && j == y2 - 1)
            {
                if (temp == 0)
                    white++;
                else
                    black++;
            }
        }
    }
}