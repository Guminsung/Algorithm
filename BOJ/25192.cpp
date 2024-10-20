#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, sum = 0;
    string s;
    set<string> h;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "ENTER")
        {
            sum += h.size();
            h.clear();
        }
        else
        {
            h.insert(s);
        }
    }
    sum += h.size();
    cout << sum;
    return 0;
}