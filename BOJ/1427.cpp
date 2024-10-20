#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    sort(s.begin(), s.end(),greater<>());
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i];
    }
    return 0;
}