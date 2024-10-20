#include <iostream>
using namespace std;
int tree[8000000];
void tree_change(int s, int e, int idx, int node);
int tree_pop(int s, int e, int node, int k);
int mx = 2000000;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, num, t, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> x;
		if (t == 1)
			tree_change(1, mx, x, 1);
		else
		{
			num = tree_pop(1, mx, 1, x);
			cout << num << "\n";
		}
	}
	return 0;
}


void tree_change(int s, int e, int idx, int node)
{
	if (idx < s || idx > e)
		return;
	tree[node] ++;
	if (s == e)
		return;
	int m = (s + e) / 2;
	tree_change(s, m, idx, node * 2);
	tree_change(m + 1, e, idx, node * 2 + 1);
}

int tree_pop(int s, int e, int node, int k)
{
	tree[node]--;
	if (s == e)
		return s;
	int m = (s + e) / 2;
	if (tree[node * 2] >= k)
	{
		return tree_pop(s, m, node * 2, k);
	}
	else
		return tree_pop(m + 1, e, node * 2 + 1, k - tree[node * 2]);
}