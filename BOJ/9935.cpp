#include <iostream>
#include <vector>
using namespace std;
vector<char> stack;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, f;
    cin >> s >> f;
    for (int i = 0; i < s.size(); i++)
    {
        stack.push_back(s[i]);
        if (stack[stack.size() - 1] == f[f.size() - 1])
            if (stack.size() >= f.size())
            {
                bool bomb = true;
                for (int j = 0; j < f.size(); j++)
                    if (stack[stack.size() - 1 - j] != f[f.size() - 1 - j])
                    {
                        bomb = false;
                        break;
                    }
                if (bomb == true)
                    for (int j = 0; j < f.size(); j++)
                        stack.pop_back();
            }
    }
    if (stack.size() == 0)
        cout << "FRULA";
    else
        for (int i = 0; i < stack.size(); i++)
            cout << stack[i];
    return 0;
}