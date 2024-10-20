#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long v[30];
vector<long long> Left;
vector<long long> Right;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, cnt = 0;
    long long c;
    cin >> n >> c;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    int half = n / 2;
    Left.push_back(0);
    for (int i = 0; i < half; i++)
    {
        int temp = Left.size();
        for (int j = 0; j < temp; j++)
            Left.push_back(Left[j] + v[i]);
    }
    Right.push_back(0);
    for (int i = half; i < n; i++)
    {
        int temp = Right.size();
        for (int j = 0; j < temp; j++)
            Right.push_back(Right[j] + v[i]);
    }
    sort(Right.begin(), Right.end());
    for (int i = 0; i < Left.size(); i++)
    {
        long long temp = Left[i];
        int s = 0, e = Right.size() - 1;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (temp + Right[m] <= c)
            {
                cnt += m - s + 1;
                s = m + 1;
            }
            else
                e = m - 1;
        }
    }
    cout << cnt;
    return 0;
}