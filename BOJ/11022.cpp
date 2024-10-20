#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T,a,b,sum;
    vector<int> v1,v2,v3;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> a >> b;
        v1.push_back(a);
        v2.push_back(b);
        v3.push_back(a+b);
    }
    for(int i=0;i<v3.size();i++)
     cout << "Case #" << i+1 << ": " << v1[i] << " + " << v2[i] << " = " << v3[i] << endl;
    return 0;
}