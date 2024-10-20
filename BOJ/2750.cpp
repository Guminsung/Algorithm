#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n, num, temp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}