#include <iostream>
using namespace std;
int make_tree(int s, int e, int node);
int query(int s, int e, int node, int k);
int tree[400000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, idx = 1;
    cin >> n >> k;
    make_tree(1, n, 1);
    cout << "<";
    for (int i = 0; i < n; i++)
    {
        idx += k - 1;
        if (idx % tree[1] == 0)
            idx = tree[1];
        else if (idx > tree[1])
            idx %= tree[1];
        int num = query(1, n, 1, idx);
        cout << num;
        if (i < n - 1)
            cout << ", ";
    }
    cout << ">";
    return 0;
}

int make_tree(int s, int e, int node)
{
    if (s == e)
        return tree[node] = 1;
    int m = (s + e) / 2;
    return tree[node] = make_tree(s, m, node * 2) + make_tree(m + 1, e, node * 2 + 1);
}

int query(int s, int e, int node, int k)
{
    tree[node]--;
    if (s == e)
        return s;
    int m = (s + e) / 2;
    if (tree[node * 2] >= k)
        return query(s, m, node * 2, k);
    else
        return query(m + 1, e, node * 2 + 1, k - tree[node * 2]);
}