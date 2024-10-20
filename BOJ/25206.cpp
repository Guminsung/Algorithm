#include <iostream>
using namespace std;

int main()
{
    string s1,s2;
    double n, sum = 0, avg = 0;
    for (int i = 0; i < 20; i++)
    {
        cin >> s1 >> n >> s2;
        sum += n;
        if (s2[0] == 'A')
            avg += 4 * n;
        else if (s2[0] == 'B')
            avg += 3 * n;
        else if (s2[0] == 'C')
            avg += 2 * n;
        else if (s2[0] == 'D')
            avg += n;
        else if (s2[0] == 'P')
            sum -= n;
        if (s2[1] == '+')
            avg += n / 2;
    }
    cout << avg / sum;
    return 0;
}