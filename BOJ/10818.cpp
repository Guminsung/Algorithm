#include <iostream>
using namespace std;

int main()
{
    int N,max=-1000000,min=1000000,num;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> num;
        if(num<min)
         min = num;
        if(num>max)
         max = num;
    }
    cout << min << " " << max;
    return 0;
}