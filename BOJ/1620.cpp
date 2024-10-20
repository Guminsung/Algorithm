#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num;
    string s;
    unordered_map<int, string> h1;
    unordered_map<string, int> h2;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        h1[i] = s;
        h2[s] = i;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (s[0] < 60)
        {
            num = stoi(s) - 1;
            cout << h1[num] << "\n";
        }
        else
        {
            num = h2[s] + 1;
            cout << num << "\n";
        }
    }
    return 0;
}