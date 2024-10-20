#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.size(); i += n)
        cout << s[i];
    return 0;
}