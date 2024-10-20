#include <iostream>
using namespace std;

int main()
{
    string s;
    int sum=0;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if(((int)s[i]-65)<18)
        {
            sum += (((int)s[i]-65) / 3) + 3;
        }
        else if(((int)s[i]-65)==18)
        {
            sum += 8;
        }
        else if(((int)s[i]-66)<24)
        {
            sum += (((int)s[i]-66) / 3) + 3;
        }
        else
        {
            sum += 10;
        }
    }
    cout << sum;
    return 0;
}