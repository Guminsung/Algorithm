#include <iostream>
using namespace std;
long long make_tree(int s, int e, int node);
void lazy_tree(int s, int e, int node);
long long update_tree(int s, int e, int node, int l, int r, long long dif);
long long search_tree(int s, int e, int node, int idx);
long long v[100001];
long long tree[300000];
long long lazy[300000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, a, b, k;
    long long num;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        v[i] = num;
    }
    make_tree(1, n, 1);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> q;
        if (q == 1)
        {
            cin >> a >> b >> k;
            update_tree(1, n, 1, a, b, k);
        }
        else
        {
            cin >> k;
            num = search_tree(1, n, 1, k);
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

void lazy_tree(int s, int e, int node)
{
    if (lazy[node] != 0)
    {
        if (s != e)
        {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        tree[node] += lazy[node] * (e - s + 1);
        lazy[node] = 0;
    }
}

long long update_tree(int s, int e, int node, int l, int r, long long dif)
{
    lazy_tree(s, e, node);
    if (e < l || s > r)
        return tree[node];
    if (s >= l && e <= r)
    {
        lazy[node] += dif;
        lazy_tree(s, e, node);
        return tree[node];
    }
    int m = (s + e) / 2;
    return tree[node] = update_tree(s, m, node * 2, l, r, dif) + update_tree(m + 1, e, node * 2 + 1, l, r, dif);
}

long long search_tree(int s, int e, int node, int idx)
{
    lazy_tree(s, e, node);
    if (e < idx || s > idx)
        return 0;
    if (s == e)
        return tree[node];
    int m = (s + e) / 2;
    return search_tree(s, m, node * 2, idx) + search_tree(m + 1, e, node * 2 + 1, idx);
}