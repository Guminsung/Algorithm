#include <iostream>
using namespace std;
void DC(int x1, int x2, int y1, int y2);
string v[64];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        v[i] = s;
    }
    DC(0, n, 0, n);
    return 0;
}

void DC(int x1, int x2, int y1, int y2)
{
    char temp = v[x1][y1];
    bool stop = true;
    for (int i = x1; i < x2; i++)
    {
        if (stop == false)
            break;
        for (int j = y1; j < y2; j++)
        {
            if (temp != v[i][j])
            {
                cout << "(";
                DC(x1, (x1 + x2) / 2, y1, (y1 + y2) / 2);
                DC(x1, (x1 + x2) / 2, (y1 + y2) / 2, y2);
                DC((x1 + x2) / 2, x2, y1, (y1 + y2) / 2);
                DC((x1 + x2) / 2, x2, (y1 + y2) / 2, y2);
                cout << ")";
                stop = false;
                break;
            }
            if (i == x2 - 1 && j == y2 - 1)
                cout << temp;
        }
    }
}