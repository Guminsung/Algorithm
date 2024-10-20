#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, cnt = 0;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            cin >> num;
        cnt++;
        cout << "Case " << cnt << ": Sorting... done!" << "\n";
    }
    return 0;
}