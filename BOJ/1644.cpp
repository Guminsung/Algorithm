#include <iostream>
#include <vector>
using namespace std;
bool prime[4000001];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, sum = 0, cnt = 0;
    cin >> n;
    for (int i = 2; i <= n; i++)
        prime[i] = true;
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == true)
            for (int j = 2; j * i <= n; j++)
                if (prime[j * i] == true)
                    prime[j * i] = false;
    }
    for (int i = 2; i <= n; i++)
        if (prime[i] == true)
            v.push_back(i);
    int s = 0, e = 0;
    if (v.size() > 0)
        sum = v[s];
    while (e < v.size())
    {
        if (sum < n)
        {
            e++;
            sum += v[e];
        }
        else if (sum == n)
        {
            cnt++;
            e++;
            sum += v[e];
        }
        else
        {
            sum -= v[s];
            s++;
        }
    }
    cout << cnt;
    return 0;
}