#include <iostream>
using namespace std;
int v[3][1000];
int min_cost[3][1000];
int rgb(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        v[0][i] = a;
        v[1][i] = b;
        v[2][i] = c;
    }
    cout << rgb(n);
    return 0;
}

int rgb(int n)
{
    for (int i = 0; i < 3; i++)
        min_cost[i][0] = v[i][0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int min = 1000001;
            for (int k = 0; k < 3; k++)
            {
                if (min_cost[k][i - 1] < min && j != k)
                    min = min_cost[k][i - 1];
            }
            min_cost[j][i] = min + v[j][i];
        }
    }
    int min = 1000001;
    for (int i = 0; i < 3; i++)
        if (min_cost[i][n - 1] < min)
            min = min_cost[i][n - 1];
    return min;
}