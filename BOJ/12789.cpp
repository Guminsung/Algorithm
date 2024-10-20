#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, num, c = 1;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        if (num == c)
            c++;
        else if (v.size() == 0 || v.back() > num)
            v.push_back(num);
        else
            break;
    }
    if (v.size() == 0 || v.back() == c)
        cout << "Nice";
    else
        cout << "Sad";
    return 0;
}