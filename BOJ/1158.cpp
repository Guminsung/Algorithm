#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, cnt = 0;
    queue<int> q;
    int jose[5000];
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (!q.empty())
    {
        for (int i = 1; i < k; i++)
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        jose[cnt++] = q.front();
        q.pop();
    }
    cout << "<";
    for (int i = 0; i < cnt - 1; i++)
        cout << jose[i] << ", ";
    cout << jose[cnt - 1] << ">";
    return 0;
}