#include <iostream>
using namespace std;

int main()
{
    int h,m,c;
    cin >> h >> m >> c;
    m += c;
    while(m>=60)
    {
        m -= 60;
        h++;
    }
    if(h>=24)
     h -= 24;
    cout << h << " " << m;
    return 0;
}