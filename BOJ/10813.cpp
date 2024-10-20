#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m,i,j,temp;
    vector<int> v;
    cin >> n >> m;
    for(int k=1;k<=n;k++)
    {
        v.push_back(k);
    }
    for(int k=0;k<m;k++)
    {
        cin >> i >> j;
        temp = v[i-1];
        v[i-1] = v[j-1];
        v[j-1] = temp;
    }
    for(int k=0;k<n;k++)
    {
        cout << v[k] << " ";
    }
    return 0;
}