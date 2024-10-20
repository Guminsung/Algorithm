#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num;
    unordered_map<int, int> h;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        h[num]++;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        cout << h[num] << " ";
    }
    return 0;
}