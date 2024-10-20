#include <iostream>
#include <vector>
using namespace std;
int A[1000000];
vector<int> stack;

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
        A[i] = num;
    }
    for (int i = 0; i < n; i++)
    {
        if (stack.size() == 0)
            stack.push_back(i);
        else if (A[i] <= A[stack[stack.size() - 1]])
            stack.push_back(i);
        else
        {
            for (int j = stack.size() - 1; j >= 0; j--)
            {
                if (A[i] > A[stack[j]])
                {
                    A[stack[j]] = A[i];
                    stack.pop_back();
                }
                else
                    break;
            }
            stack.push_back(i);
        }
    }
    if (stack.size() > 0)
        for (int i = 0; i < stack.size(); i++)
            A[stack[i]] = -1;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}