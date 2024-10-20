#include <iostream>
using namespace std;

int main()
{
    int A, B, a, b, temp;
    cin >> A >> B;
    if (A > B)
    {
        a = A;
        b = B;
    }
    else
    {
        a = B;
        b = A;
    }
    while (1)
    {
        temp = a % b;
        if (temp == 0)
            break;
        a = b;
        b = temp;
    }
    cout << b << "\n"
         << A * B / b;
}