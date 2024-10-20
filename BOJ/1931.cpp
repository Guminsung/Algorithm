#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
deque<pair<unsigned int, unsigned int>> p;

bool compare(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, c = 0;
    unsigned int a, b, num = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        p.push_front(make_pair(a, b));
    }
    sort(p.begin(), p.end(), compare);
    while (p.size() > 0)
    {
        if (num <= p[0].first)
        {
            c++;
            num = p[0].second;
            p.pop_front();
        }
        else
            p.pop_front();
    }
    cout << c;
    return 0;
}

bool compare(pair<unsigned int, unsigned int> a, pair<unsigned int, unsigned int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}