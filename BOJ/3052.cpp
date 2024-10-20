#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a,count=0;
    vector<int> v;
    for(int i=0;i<42;i++)
    {
        v.push_back(1);
    }
    for(int i=0;i<10;i++)
    {
        cin >> a;
        v[a%42] = 0;
    }
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==0)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}