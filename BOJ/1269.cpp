#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num, c = 0;
    unordered_map<int, int> h;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        h[num] = 1;
        c++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        if (h[num] == 1)
            c--;
        else
            c++;
    }
    cout << c;
    return 0;
}