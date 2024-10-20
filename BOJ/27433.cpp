#include <iostream>
using namespace std;

long long factorial(int n)
{
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	long long f;
	cin >> n;
	f = factorial(n);
	cout << f;
	return 0;
}