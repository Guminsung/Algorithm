#include <iostream>
#include <cmath>
using namespace std;
int t[4][6];
int decimal[6];

int main()
{
    int tm, num;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 6; j++)
        {
            cin >> num;
            t[i % 4][j] += num;
        }
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 6; j++)
        {
            int temp = t[i][j] * (int)pow(2, 3 - i);
            decimal[j] += temp;
        }
    tm = decimal[0] * 36000 + decimal[1] * 3600 + decimal[2] * 600 + decimal[3] * 60 + decimal[4] * 10 + decimal[5];
    tm %= 3600 * 24;
    decimal[0] = tm / 36000, tm %= 36000;
    decimal[1] = tm / 3600, tm %= 3600;
    decimal[2] = tm / 600, tm %= 600;
    decimal[3] = tm / 60, tm %= 60;
    decimal[4] = tm / 10, tm %= 10;
    decimal[5] = tm;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int temp = decimal[j] / (int)pow(2, 3 - i);
            cout << temp << " ";
            decimal[j] %= (int)pow(2, 3 - i);
        }
        cout << "\n";
    }
}