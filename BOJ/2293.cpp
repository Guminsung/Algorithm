#include <iostream>
#include <vector>
using namespace std;
void coin(int k);
vector<int> v;
int dp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, num;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num <= k)
            v.push_back(num);
    }
    coin(k);
    cout << dp[k];
    return 0;
}

void coin(int k)
{
    dp[0] = 1;
    for (int i = 0; i < v.size(); i++)
        for (int j = v[i]; j <= k; j++)
            dp[j] += dp[j - v[i]];
}