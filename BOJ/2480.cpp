#include <iostream>
using namespace std;

int main()
{
    int a, b, c, price, top;
    cin >> a >> b >> c;
    if((a==b)&&(b==c))
    {
        price = 10000 + a*1000;
        cout << price;
    }
    else if(a==b)
    {
        price = 1000 + a*100;
        cout << price;
    }
    else if(b==c)
    {
        price = 1000 + b*100;
        cout << price;
    }
    else if(a==c)
    {
        price = 1000 + a*100;
        cout << price;
    }
    else
    {
        top = a;
        if(top<b)
         top = b;
        if(top<c)
         top = c;
        price = top*100;
        cout << price;
    }
    return 0;
}