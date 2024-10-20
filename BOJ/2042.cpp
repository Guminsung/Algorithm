#include <iostream>
using namespace std;
long long v[1000000];
long long tree[2100000];
long long make_tree(int s, int e, int node);
void tree_change(int s, int e, int idx, int node, long long dif);
long long tree_sum(int s, int e, int node, int l, int r);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, a, b;
    long long num, c;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    make_tree(0, n - 1, 1);
    for (int i = 0; i < m + k; i++)
    {
        cin >> a >> b >> c;
        if (a == 1)
        {
            long long dif = c - v[b - 1];
            v[b - 1] = c;
            tree_change(0, n - 1, b - 1, 1, dif);
        }
        else
        {
            num = tree_sum(0, n - 1, 1, b - 1, c - 1);
            cout << num << "\n";
        }
    }
    return 0;
}

long long make_tree(int s, int e, int node)
{
    if (s == e)
        return tree[node] = v[s];
    int m = (s + e) / 2;
    return tree[node] = make_tree(s, m, node * 2) + make_tree(m + 1, e, node * 2 + 1);
}

void tree_change(int s, int e, int idx, int node, long long dif)
{
    if (idx < s || idx > e)
        return;
    tree[node] += dif;
    if (s == e)
        return;
    int m = (s + e) / 2;
    tree_change(s, m, idx, node * 2, dif);
    tree_change(m + 1, e, idx, node * 2 + 1, dif);
}

long long tree_sum(int s, int e, int node, int l, int r)
{
    if (e < l || s > r)
        return 0;
    if (s >= l && e <= r)
        return tree[node];
    int m = (s + e) / 2;
    return tree_sum(s, m, node * 2, l, r) + tree_sum(m + 1, e, node * 2 + 1, l, r);
}