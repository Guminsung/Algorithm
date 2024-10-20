#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int num, temp, sum = 0;
    double avg;
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        sum += num;
        v.push_back(num);
    }
    avg = sum / 5;
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (v[i] > v[i + 1])
            {
                temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
    cout << avg << endl
         << v[2];
    return 0;
}