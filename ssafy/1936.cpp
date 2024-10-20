#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b;
    cin >> a >> b;
    if (a == 3 && b == 1 || a < b)
        cout << "B";
    else
        cout << "A";
    return 0;
}