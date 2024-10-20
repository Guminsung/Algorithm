#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, check, sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> n;
        sum += n * n;
    }
    check = sum % 10;
    cout << check;
    return 0;
}