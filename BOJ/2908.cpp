#include <iostream>
using namespace std;

int main()
{
    string a,b;
    int A,B;
    cin >> a >> b;
    A = (int)a[0]-48 + (int)(a[1]-48)*10 + (int)(a[2]-48)*100;
    B = (int)b[0]-48 + (int)(b[1]-48)*10 + (int)(b[2]-48)*100;
    if(A>B)
    {
        cout << A;
    }
    else
    {
        cout << B;
    }
    return 0;
}