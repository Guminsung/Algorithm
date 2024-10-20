#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N,a,f,c=0;
    vector<int> v;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> a;
        v.push_back(a);
    }
    cin >> f;
    for(int i=0;i<N;i++)
    {
        if(v[i]==f)
        {
            c++;
        }
    }
    cout << c;
    return 0;
}