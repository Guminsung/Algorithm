#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n, k, num, temp, sum = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        sum += num;
        v.push_back(num);
    }
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] < v[i + 1])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
    cout << v[k-1];
    return 0;
}