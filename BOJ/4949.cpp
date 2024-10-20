#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    while (true)
    {
        vector<char> v;
        getline(cin, s);
        if (s[0] == '.')
            break;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == ')' && v.size() != 0 && v.back() == '(')
                v.pop_back();
            else if (s[j] == ']' && v.size() != 0 && v.back() == '[')
                v.pop_back();
            else if ((s[j] == ')' || s[j] == ']'))
            {
                v.push_back('a');
                break;
            }
            else if (s[j] == '(' || s[j] == '[')
                v.push_back(s[j]);
            else
                continue;
        }
        if (v.size() == 0)
            cout << "yes"
                 << "\n";
        else
            cout << "no"
                 << "\n";
    }
    return 0;
}