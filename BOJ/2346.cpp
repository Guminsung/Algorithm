#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num;
    deque<pair<int, int>> d;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        d.push_back(make_pair(i, num));
    }
    while (!d.empty())
    {
        cout << d[0].first << " ";
        num = d[0].second;
        d.pop_front();
        if (num > 0)
            for (int i = 1; i < num; i++)
            {
                d.push_back(d.front());
                d.pop_front();
            }
        else
            for (int i = 0; i < -num; i++)
            {
                d.push_front(d.back());
                d.pop_back();
            }
    }
    return 0;
}