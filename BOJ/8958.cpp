#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int n, c = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == 'O')
            {
                sum += ++c;
            }
            else
                c = 0;
        }
        cout << sum << "\n";
        sum = 0;
        c = 0;
    }
    return 0;
}