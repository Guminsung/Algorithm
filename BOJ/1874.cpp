#include <iostream>
#include <vector>
using namespace std;
int v[100000];
vector<int> stack;
vector<char> c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, num, cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == v[cnt])
        {
            stack.push_back(i);
            c.push_back('+');
            for (int j = stack.size() - 1; j >= 0; j--)
            {
                if (stack[j] == v[cnt])
                {
                    stack.pop_back();
                    c.push_back('-');
                    cnt++;
                }
                else
                    break;
            }
        }
        else
        {
            stack.push_back(i);
            c.push_back('+');
        }
    }
    if (stack.size() == 0)
        for (int i = 0; i < c.size(); i++)
            cout << c[i] << "\n";
    else
        cout << "NO";
    return 0;
}