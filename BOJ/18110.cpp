#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, temp, avg = 0, sum = 0;
    vector<int> v;
    cin >> n;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(), v.end());
        num = n * 15 / 100;
        temp = n * 15 % 100;
        if (temp >= 50)
            num++;
        for (int i = num; i < n - num; i++)
            sum += v[i];
        avg = sum / (n - num * 2);
        temp = sum % (n - num * 2);
        if (temp * 2 >= (n - num * 2))
            avg++;
    }
    cout << avg;
    return 0;
}