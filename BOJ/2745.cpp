#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    string s;
    int b, sum = 0;
    cin >> s >> b;
    for (int i = 0; i < s.size(); i++)
    {
        if ((int)s[i] < 65)
        {
            sum += ((int)s[i] - 48) * pow(b, (s.size() - i - 1));
        }
        else
        {
            sum += ((int)s[i] - 55) * pow(b, (s.size() - i - 1));
        }
    }
    cout << sum;
    return 0;
}