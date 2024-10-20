#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v(10001, 0);
    int n, num;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[num]++;
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (v[i] != 0)
        {
            for (int j = 0; j < v[i]; j++)
            {
                cout << i << "\n";
            }
        }
    }
    return 0;
}