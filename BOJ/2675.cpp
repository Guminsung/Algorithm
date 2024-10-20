#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string s;
    int t, r;
    vector<char> v;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> r >> s;
        for (int k = 0; k < s.size(); k++)
        {
            for (int j = 0; j < r; j++)
            {
                v.push_back(s[k]);
            }
        }
        v.push_back('a');
    }
    
    for (int i = 0; i < v.size()-1; i++)
    {
        if (v[i] == 'a')
        {
            cout << endl;
            i++;
        }
        cout << v[i];
    }
    
    return 0;
}