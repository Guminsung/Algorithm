#include <iostream>
using namespace std;

void hanoi(int n, int f, int s);

int main()
{
    int n, k = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
        k *= 2;
    k--;
    cout << k << "\n";
    hanoi(n, 1, 3);
    return 0;
}

void hanoi(int n, int f, int s)
{
    if (n > 1)
        hanoi(n - 1, f, 6 - f - s);
    cout << f << " " << s << "\n";
    if (n > 1)
        hanoi(n - 1, 6 - f - s, s);
}