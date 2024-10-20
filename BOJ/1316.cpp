#include <iostream>
using namespace std;

int main()
{
    string s;
    int n, c = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int v[26] = {0};
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if (v[(int)s[j] - 97] == 0)
            {
                v[(int)s[j] - 97] = 1;
            }
            else if (s[j] != s[j - 1])  
            {
                c--;
                break;
            }
        }
        c++;
    }
    cout << c;
    return 0;
}