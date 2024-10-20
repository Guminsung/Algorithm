#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int tall[500000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, same = 0;
    long long cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        tall[i] = num;
    }
    for (int i = 0; i < n; i++)
    {
        if (v.size() == 0)
            v.push_back(make_pair(tall[i], 1));
        else if (v[v.size() - 1].first > tall[i])
        {
            cnt++;
            v.push_back(make_pair(tall[i], 1));
        }
        else if (v[v.size() - 1].first == tall[i])
        {
            if (v.size() > v[v.size() - 1].second)
                cnt += v[v.size() - 1].second + 1;
            else
                cnt += v[v.size() - 1].second;
            v.push_back(make_pair(tall[i], v[v.size() - 1].second + 1));
        }
        else
        {
            for (int j = v.size() - 1; j >= 0; j--)
                if (v[j].first < tall[i])
                {
                    cnt++;
                    v.pop_back();
                }
                else
                    break;
            if (v.size() > 0)
            {
                if (v[v.size() - 1].first == tall[i])
                {
                    if (v.size() > v[v.size() - 1].second)
                        cnt += v[v.size() - 1].second + 1;
                    else
                        cnt += v[v.size() - 1].second;
                    v.push_back(make_pair(tall[i], v[v.size() - 1].second + 1));
                }
                else
                {
                    cnt++;
                    v.push_back(make_pair(tall[i], 1));
                }
            }
            else
                v.push_back(make_pair(tall[i], 1));
        }
    }
    cout << cnt;
    return 0;
}