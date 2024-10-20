#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    string s1, s2;
    map<string, int, greater<string>> m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        if (s2 == "enter")
            m[s1] = 1;
        else if (s2 == "leave")
            m[s1] = 0;
    }
    for (auto i = m.begin(); i != m.end(); i++)
    {
        if (i->second == 1)
            cout << i->first << "\n";
    }
    return 0;
}