#include <iostream>
using namespace std;

int main()
{
    string s;
    int count=0;
    while(true)
    {
        cin >> s;
        if(cin.eof())
         break;
        count++;
    }
    cout << count;
    return 0;
}