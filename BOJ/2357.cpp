#include <iostream>
using namespace std;
int v[100000];
int mn_tree[300000];
int mx_tree[300000];
int make_mn(int s, int e, int node);
int make_mx(int s, int e, int node);
int tree_mn(int s, int e, int node, int l, int r);
int tree_mx(int s, int e, int node, int l, int r);
int INF = 1000000001;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m, num, a, b;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v[i] = num;
	}
	make_mn(0, n - 1, 1);
	make_mx(0, n - 1, 1);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		num = tree_mn(0, n - 1, 1, a - 1, b - 1);
		cout << num << " ";
		num = tree_mx(0, n - 1, 1, a - 1, b - 1);
		cout << num << "\n";
	}
	return 0;
}

int make_mn(int s, int e, int node)
{
	if (s == e)
		return mn_tree[node] = v[s];
	int m = (s + e) / 2, left, right;
	left = make_mn(s, m, node * 2);
	right = make_mn(m + 1, e, node * 2 + 1);
	mn_tree[node] = (left > right) ? right : left;
	return mn_tree[node];
}

int make_mx(int s, int e, int node)
{
	if (s == e)
		return mx_tree[node] = v[s];
	int m = (s + e) / 2, left, right;
	left = make_mx(s, m, node * 2);
	right = make_mx(m + 1, e, node * 2 + 1);
	mx_tree[node] = (left < right) ? right : left;
	return mx_tree[node];
}

int tree_mn(int s, int e, int node, int l, int r)
{
	if (e < l || s > r)
		return INF;
	if (s >= l && e <= r)
		return mn_tree[node];
	int m = (s + e) / 2, left, right, result;
	left = tree_mn(s, m, node * 2, l, r);
	right = tree_mn(m + 1, e, node * 2 + 1, l, r);
	result = (left > right) ? right : left;
	return result;
}

int tree_mx(int s, int e, int node, int l, int r)
{
	if (e < l || s > r)
		return 0;
	if (s >= l && e <= r)
		return mx_tree[node];
	int m = (s + e) / 2, left, right, result;
	left = tree_mx(s, m, node * 2, l, r);
	right = tree_mx(m + 1, e, node * 2 + 1, l, r);
	result = (left < right) ? right : left;
	return result;
}