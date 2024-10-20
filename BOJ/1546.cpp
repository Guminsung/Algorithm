#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int a,n,m=0;
    double total=0,avg;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(m<a)
        {
            m = a;
        }
        v.push_back(a);
    }
    for(int i=0;i<v.size();i++)
    {
        total += v[i]/(double)m*100;
    }
    avg = total/n;
    cout << avg;
    return 0;
}