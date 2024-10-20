#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T,a,b,sum;
    vector<int> v;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> a >> b;
        sum = a + b;
        v.push_back(sum);
    }
    for(int i=0;i<v.size();i++)
     cout << v[i] << "\n";
    return 0;
}