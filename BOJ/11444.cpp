#include <iostream>
using namespace std;
void FS(long long n);
long long v[2][2], temp[2][2], result[2][2];
int MOD = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    v[0][0] = 1, v[0][1] = 1, v[1][0] = 1, v[1][1] = 0;
    result[0][0] = 1, result[1][1] = 1;
    FS(n);
    cout << result[1][0];
    return 0;
}

void FS(long long n)
{
    if (n > 0)
    {
        long long sum = 0;
        if (n % 2 == 1)
        {
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 0; k < 2; k++)
                        sum += (result[i][k] * v[k][j]) % MOD;
                    temp[i][j] = sum % MOD;
                    sum = 0;
                }
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    result[i][j] = temp[i][j];
        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
            {
                for (int k = 0; k < 2; k++)
                    sum += (v[i][k] * v[k][j]) % MOD;
                temp[i][j] = sum % MOD;
                sum = 0;
            }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                v[i][j] = temp[i][j];
        FS(n / 2);
    }
}