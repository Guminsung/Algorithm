#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    string s;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        v.push_back(s);
    }
    for (int i = 1; i <= 200; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (stoi(v[j]) == i)
                cout << v[j] << "\n";
        }
    }
    return 0;
}