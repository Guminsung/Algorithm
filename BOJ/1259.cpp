#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num = 1;
    while (num != 0)
    {
        vector<int> v;
        cin >> num;
        for (int i = 0; i < 6; i++)
        {
            v.push_back(num % 10);
            if (num < 10)
                break;
            num /= 10;
        }
        if (v.size() == 1 && num != 0)
            cout << "yes"
                 << "\n";
        for (int i = 0; i < v.size() / 2; i++)
        {
            if (v[i] != v[v.size() - i - 1])
            {
                cout << "no"
                     << "\n";
                break;
            }
            if (i == v.size() / 2 - 1)
                cout << "yes"
                     << "\n";
        }
    }
    return 0;
}