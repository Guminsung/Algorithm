#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    bool start = true;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        if (start == true)
            start = false;
        else
            cout << "\n";
        bool v[50] = {false};
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 6; j++)
            {
                cin >> num;
                if (!v[num])
                {
                    v[num] = true;
                    cnt++;
                }
            }
        if (cnt == 49)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}