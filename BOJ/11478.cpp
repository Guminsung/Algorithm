#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num = 0, c = 0;
    string s;
    unordered_map<string, int> h;
    cin >> s;
    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 0; j < s.size() - num; j++)
        {
            if (h[s.substr(j, i)] != 1)
            {
                c++;
                h[s.substr(j, i)] = 1;
            }
        }
        num++;
    }
    cout << c;
    return 0;
}