#include <iostream>
#include <string>
using namespace std;
int v[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    int c = 0, max = -1, sum = 0;
    while (!cin.eof())
    {
        getline(cin, s);
        if (s.size() == 0)
            break;
        v[c++] = s.size();
    }
    for (int i = 0; i < c; i++)
        if (v[i] > max)
            max = v[i];
    for (int i = 0; i < c - 1; i++)
        sum += (max - v[i]) * (max - v[i]);
    cout << sum;
    return 0;
}