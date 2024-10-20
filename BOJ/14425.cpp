#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n, m, c = 0;
    string s;
    unordered_map<string, int> h;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        h[s] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if (h[s] == 1)
            c++;
    }
    cout << c;
    return 0;
}