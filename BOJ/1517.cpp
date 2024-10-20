#include <iostream>
#include <algorithm>
using namespace std;
int seg_tree(int s, int e, int idx, int node);
long long cnt_tree(int s, int e, int idx, int node);
pair<int, int> p[500000];
int tree[1100000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, num;
	long long cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		p[i] = make_pair(num, i);
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++)
	{
		cnt += cnt_tree(0, n - 1, p[i].second, 1);
		seg_tree(0, n - 1, p[i].second, 1);
	}
	cout << cnt;
	return 0;
}

int seg_tree(int s, int e, int idx, int node)
{
	if (s > idx || e < idx)
		return tree[node];
	if (s == e)
		return tree[node] = 1;
	int m = (s + e) / 2;
	return tree[node] = seg_tree(s, m, idx, node * 2) + seg_tree(m + 1, e, idx, node * 2 + 1);
}

long long cnt_tree(int s, int e, int idx, int node)
{
	if (e < idx)
		return 0;
	if (s >= idx)
		return tree[node];
	int m = (s + e) / 2;
	return cnt_tree(s, m, idx, node * 2) + cnt_tree(m + 1, e, idx, node * 2 + 1);
}