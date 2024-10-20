#include <iostream>
using namespace std;
int v[101];
int temp[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M, s, e, m;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
        v[i] = i;
    for (int i = 0; i < M; i++)
    {
        cin >> s >> e >> m;
        for (int j = 0; j < m - s; j++)
            temp[j] = v[j + s];
        for (int j = 0; j <= e - m; j++)
            v[s + j] = v[m + j];
        for (int j = 0; j < m - s; j++)
            v[s + e - m + 1 + j] = temp[j];
    }
    for (int i = 1; i <= N; i++)
        cout << v[i] << " ";
    return 0;
}