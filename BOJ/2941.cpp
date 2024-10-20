#include <iostream>
using namespace std;

int main()
{
    string s;
    int c = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (i < s.size() - 1)
        {
            if (s[i] == 'c')
            {
                if (s[i + 1] == '-' || s[i + 1] == '=')
                {
                    i++;
                }
            }
            else if (s[i] == 'd')
            {
                if (s[i + 1] == '-')
                {
                    i++;
                }
                else if (s[i + 1] == 'z' && s[i + 2] == '=' && i < s.size() - 2)
                {
                    i += 2;
                }
            }
            else if (s[i] == 'l')
            {
                if (s[i + 1] == 'j')
                {
                    i++;
                }
            }
            else if (s[i] == 'n')
            {
                if (s[i + 1] == 'j')
                {
                    i++;
                }
            }
            else if (s[i] == 's')
            {
                if (s[i + 1] == '=')
                {
                    i++;
                }
            }
            else if (s[i] == 'z')
            {
                if (s[i + 1] == '=')
                {
                    i++;
                }
            }
        }

        c++;
    }
    cout << c;
    return 0;
}