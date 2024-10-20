#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, min = 1000000001;
    long long sum = 0;
    int road[100000], oil[100000];
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> num;
        road[i] = num;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        oil[i] = num;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (min > oil[i])
            min = oil[i];
        sum += (long long)min * road[i];
    }
    cout << sum;
    return 0;
}