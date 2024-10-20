#include <iostream>
using namespace std;

int main()
{
    string s;
    int f=1;
    cin >> s;
    for(int i=0;i<=s.size()/2;i++)
    {
        if(s[i]!=s[s.size()-i-1])
        {
            f = 0;
            break;
        }
    }
    cout << f;
    return 0;
}