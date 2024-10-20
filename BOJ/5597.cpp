#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    vector<int> v;
    for(int i=1;i<=30;i++)
    {
        v.push_back(i);
    }
    for(int i=0;i<28;i++)
    {
        cin >> num;
        v[num-1] = 0;
    }
    for(int i=0;i<30;i++)
    {
        if(v[i]!=0)
        {
            cout << v[i] << endl;
        }
    }
    return 0;
}