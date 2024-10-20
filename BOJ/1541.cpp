#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool b = true;
    int num, sum = 0, c = 0;
    int v[50];
    string s;
    cin >> s;
    for (int i = 0; i <= s.size(); i++)
    {
        if (s[i] == '+' || i == s.size())
        {
            if (b == true)
                v[c++] = sum;
            else
                v[c++] = -sum;
            sum = 0;
        }
        else if (s[i] == '-')
        {
            if (b == true)
            {
                v[c++] = sum;
                b = false;
            }
            else
                v[c++] = -sum;
            sum = 0;
        }
        else
        {
            num = s[i] - '0';
            sum = sum * 10 + num;
        }
    }
    for (int i = 0; i < c; i++)
    {
        sum += v[i];
    }
    cout << sum;
    return 0;
}