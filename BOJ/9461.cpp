#include <iostream>
using namespace std;
long long P(int n);
long long v[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> n;
        cout << P(n) << "\n";
    }
    return 0;
}

long long P(int n)
{
    v[0] = 1, v[1] = 1, v[2] = 1;
    for (int i = 3; i < n; i++)
        v[i] = v[i - 2] + v[i - 3];
    return v[n - 1];
}