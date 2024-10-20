#include <iostream>
using namespace std;

int main()
{
    char c;
    int n,sum=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        sum += (int)c-48;
    }
    cout << sum;
    return 0;
}