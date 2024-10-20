#include <iostream>
#include <cmath>
using namespace std;

void Cantorian_set(int start, int end);

int v[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, N;
    while (cin >> n)
    {
        N = pow(3, n);
        Cantorian_set(1, N);
        for (int i = 1; i <= N; i++)
        {
            if (v[i] == 1)
                cout << "-";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}

void Cantorian_set(int start, int end)
{
    if (start == 1 && end == 1)
    {
        v[1] = 1;
    }
    if (start != end)
    {
        int p = (end - start + 1) / 3;
        for (int i = start; i <= end; i++)
            v[i] = 1;
        for (int i = start + p; i <= end - p; i++)
            v[i] = 0;
        Cantorian_set(start, start + p - 1);
        Cantorian_set(end - p + 1, end);
    }
}