#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    vector<char> v;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> str;
        v.push_back(str[0]);
        v.push_back(str[str.size()-1]);
    }
    for(int i=0;i<v.size();i+=2)
    {
        cout << v[i] << v[i+1] << endl;
    }
    return 0;
}