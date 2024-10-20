#include <iostream>
using namespace std;
int PS[26][200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int q, l, r;
    char c;
    cin >> s >> q;
    for (int i = 0; i < 26; i++)
        for (int j = 1; j <= s.size(); j++)
            if ((int)s[j - 1] == i + 97)
                PS[i][j] = PS[i][j - 1] + 1;
            else
                PS[i][j] = PS[i][j - 1];
    for (int i = 0; i < q; i++)
    {
        cin >> c >> l >> r;
        cout << PS[(int)c - 97][r + 1] - PS[(int)c - 97][l] << "\n";
    }
    return 0;
}