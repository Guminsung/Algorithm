#include <iostream>
#include <unordered_map>
using namespace std;
int v[500000];

int main()
{
    int n, m, num;
    unordered_map<int, int> h;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        h[num] = 1;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> v[i];
    }   
    for (int i = 0; i < m; i++)
    {
        if (h[v[i]] == 1)
            cout << "1"
                 << " ";
        else
            cout << "0"
                 << " ";
    }
    return 0;
}