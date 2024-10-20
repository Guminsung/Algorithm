#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        vector<char> v;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == ')' && v.size() != 0)
                v.pop_back();
            else if (s[j] == ')')
            {
                v.push_back('1');
                break;
            }
            else
                v.push_back(s[j]);
        }
        if (v.size() == 0)
            cout << "YES"
                 << "\n";
        else
            cout << "NO"
                 << "\n";
    }
    return 0;
}