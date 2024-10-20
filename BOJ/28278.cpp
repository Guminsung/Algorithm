#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num, a;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        switch (num)
        {
        case 1:
            cin >> a;
            v.push_back(a);
            break;
        case 2:
            if (v.size() == 0)
                cout << "-1"
                     << "\n";
            else
            {
                a = v.back();
                cout << a << "\n";
                v.pop_back();
            }
            break;
        case 3:
            a = v.size();
            cout << a << "\n";
            break;
        case 4:
            if (v.size() == 0)
                cout << "1"
                     << "\n";
            else
                cout << "0"
                     << "\n";
            break;
        case 5:
            if (v.size() == 0)
                cout << "-1"
                     << "\n";
            else
            {
                a = v.back();
                cout << a << "\n";
            }
        }
    }
    return 0;
}