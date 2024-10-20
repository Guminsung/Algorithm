#include <iostream>
using namespace std;

int main()
{
    int c,t,q,d,n,p;
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> c;
        q=c/25;
        c=c%25;
        d=c/10;
        c=c%10;
        n=c/5;
        c=c%5;
        p=c;
        cout << q << " " << d << " " << n << " " << p << endl;  
    }
    return 0;
}