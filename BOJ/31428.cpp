#include <iostream>
using namespace std;
int track[4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    char c;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        if (c == 'C')
            track[0]++;
        else if (c == 'S')
            track[1]++;
        else if (c == 'I')
            track[2]++;
        else
            track[3]++;
    }
    cin >> c;
    if (c == 'C')
        cout << track[0];
    else if (c == 'S')
        cout << track[1];
    else if (c == 'I')
        cout << track[2];
    else
        cout << track[3];
    return 0;
}