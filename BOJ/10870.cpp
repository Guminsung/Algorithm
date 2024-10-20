#include <iostream>
using namespace std;

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, f;
	cin >> n;
	f = Fibonacci(n);
	cout << f;
	return 0;
}