#include <iostream>
using namespace std;

int main()
{
    string s;
    int v[26]={ 0 };
    int max=0,num;
    cin >> s;
    for(int i=0;i<s.size();i++)
    {
        if((int)s[i]<=90)
        {
            v[(int)s[i]-65]++;
        }
        else
        {
            v[(int)s[i]-97]++;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(max<v[i])
        {
            max = v[i];
            num = i;
            continue;
        }
        if(max==v[i])
        {
            num = -1;
        }
    }
    if(num==-1)
    {
        cout << "?";
    }
    else
    {
        cout <<(char)(num+65);
    }
    return 0;
}