#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    vector<int> v;
    for(int i=0;i<26;i++)
    {
        v.push_back(-1);
    }
    cin >> str;
    for(int i=0;i<str.size();i++)
    {
        if(v[(int)str[i]-97]==-1)
        {
            v[(int)str[i]-97] = i;
        }
    }
    for(int i=0;i<26;i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}