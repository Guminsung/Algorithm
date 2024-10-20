#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    vector<vector<char>> v2;
    for (int i = 0; i < 5; i++)
    {
        vector<char> v;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            v.push_back(s[j]);
        }
        for (int j = s.size(); j < 15; j++)
        {
            v.push_back('*');
        }
        v2.push_back(v);
    }
    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (v2[i][j] == '*')
                continue;
            cout << v2[i][j];
        }
    }
    return 0;
}