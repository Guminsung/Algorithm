#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k, num;
    unsigned int sum = 0;
    vector<int> v;
    cin >> k;
    for(int i=0;i<k;i++)
    {
        cin >> num;
        if(num==0)
        v.pop_back();
        else
        v.push_back(num);
    }
    for(int i=0;i<v.size();i++)
    {
        sum += v[i];
    }
    cout << sum;
    return 0;
}