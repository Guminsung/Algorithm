#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N,X,a;
    vector<int> v;
    cin >> N >> X;
    for(int i=0;i<N;i++)
    {
        cin >> a;
        v.push_back(a);
    }
    for(int i=0;i<v.size();i++)
    {
        if(X>v[i])
        {
            cout << v[i] << " ";
        }
    }
    return 0;
}