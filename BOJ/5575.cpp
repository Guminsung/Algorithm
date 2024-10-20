#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v[3][3];
    int bh, bm, bs, ah, am, as;
    for (int i = 0; i < 3; i++)
    {
        cin >> bh >> bm >> bs >> ah >> am >> as;
        v[i][2] = as - bs;
        v[i][1] = am - bm;
        v[i][0] = ah - bh;
        if (v[i][2] < 0)
        {
            v[i][1]--;
            v[i][2] += 60;
        }
        if (v[i][1] < 0)
        {
            v[i][0]--;
            v[i][1] += 60;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
    return 0;
}