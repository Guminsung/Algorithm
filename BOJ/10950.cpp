#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T, A, B, sum;
    vector<int> v;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        cin >> A >> B;
        sum = A + B;
        v.push_back(sum);
    }
    for(int i=0;i<v.size();i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}