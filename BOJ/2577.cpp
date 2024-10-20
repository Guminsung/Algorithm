#include <iostream>
using namespace std;
int v[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a, b, c, num;
    cin >> a >> b >> c;
    num = a * b * c;
    while (num > 0)
    {
        v[num % 10]++;
        num /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << v[i] << "\n";
    }
    return 0;
}