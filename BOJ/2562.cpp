#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a,num,max=0;
    vector<int> v;
    while(true)
    {
        cin >> a;
        v.push_back(a);
        if(cin.eof())
         break;
    }
    for(int i=0;i<v.size();i++)
    {
        if(max<v[i])
        {
            max = v[i];
            num = i+1;
        }
    }
    cout << max << "\n" << num;
    return 0;
}