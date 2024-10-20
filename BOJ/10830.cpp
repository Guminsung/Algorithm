#include <iostream>
using namespace std;
void SM(int n, long long b);
int a[5][5], v[5][5], result[5][5];
int MOD = 1000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num;
    long long b;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            a[i][j] = num;
        }
    for (int i = 0; i < n; i++)
        result[i][i] = 1;
    SM(n, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
    return 0;
}

void SM(int n, long long b)
{
    if (b > 0)
    {
        int sum = 0;
        if (b % 2 == 1)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                {
                    for (int l = 0; l < n; l++)
                        sum += (result[i][l] * a[l][j]) % MOD;
                    v[i][j] = sum % MOD;
                    sum = 0;
                }
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    result[i][j] = v[i][j];
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                for (int l = 0; l < n; l++)
                    sum += (a[i][l] * a[l][j]) % MOD;
                v[i][j] = sum % MOD;
                sum = 0;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = v[i][j];
        SM(n, b / 2);
    }
}