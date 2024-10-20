#include <iostream>
#include <deque>
using namespace std;
int a[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, num;
    deque<int> d;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        a[i] = num;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (a[i] == 0)
        {
            d.push_front(num);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        d.push_back(num);
        cout << d.front() << " ";
        d.pop_front();
    }
    return 0;
}