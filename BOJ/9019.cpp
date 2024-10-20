#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int DSLR(int n, int num);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, a, b;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        queue<int> q;
        vector<int> v;
        pair<int, int> visited[10000];
        cin >> a >> b;
        q.push(a);
        while (q.front() != b)
        {
            int temp = q.front();
            q.pop();
            for (int j = 1; j <= 4; j++)
            {
                if (visited[DSLR(temp, j)].second == 0)
                {
                    visited[DSLR(temp, j)] = make_pair(temp, j);
                    q.push(DSLR(temp, j));
                }
            }
        }
        while (b != a)
        {
            v.push_back(visited[b].second);
            b = visited[b].first;
        }
        while (!v.empty())
        {
            if (v[v.size() - 1] == 1)
                cout << 'D';
            else if (v[v.size() - 1] == 2)
                cout << 'S';
            else if (v[v.size() - 1] == 3)
                cout << 'L';
            else
                cout << 'R';
            v.pop_back();
        }
        cout << "\n";
    }
    return 0;
}

int DSLR(int n, int num)
{
    if (num == 1)
    {
        int temp = (n * 2) % 10000;
        return temp;
    }
    else if (num == 2)
    {
        int temp;
        if (n == 0)
            temp = 9999;
        else
            temp = n - 1;
        return temp;
    }
    else if (num == 3)
    {
        int temp = (n % 1000) * 10 + n / 1000;
        return temp;
    }
    else
    {
        int temp = n / 10 + (n % 10) * 1000;
        return temp;
    }
}