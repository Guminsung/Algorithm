#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    string s1, s2;
    map<string, int> m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s1 >> s2;
        if (s1 == "ChongChong" || s2 == "ChongChong")
        {
            m[s1] = 1;
            m[s2] = 1;
        }
        else
        {
            if (m.find(s1)->second == 1)
                m[s2] = 1;
            else if (m.find(s2)->second == 1)
                m[s1] = 1;
            else
                continue;
        }
    }
    cout << m.size();
    return 0;
}