#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a,b;
    vector<int> v;
    while(1)
    {
        cin >> a >> b;
        if(cin.eof()==true)
         break;
        v.push_back(a+b);
    }
    for(int i=0;i<v.size();i++)
     cout << v[i] << endl;
    return 0;
}