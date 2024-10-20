#include <iostream>
#include <algorithm>
using namespace std;
void bk(int cnt);
int v[7], p[7];
int n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    sort(v, v + n);
    bk(0);
    return 0;
}

void bk(int cnt)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << p[i] << " ";
        cout << "\n";
    }
    else
        for (int i = 0; i < n; i++)
        {
            p[cnt] = v[i];
            bk(cnt + 1);
        }
}