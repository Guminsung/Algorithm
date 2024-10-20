#include <iostream>
using namespace std;

int main()
{
    int K,Q,L,B,N,P;
    cin >> K >> Q >> L >> B >> N >> P;
    K = 1 - K;
    Q = 1 - Q;
    L = 2 - L;
    B = 2 - B;
    N = 2 - N;
    P = 8 - P;
    cout << K << " " << Q << " " << L << " " << B << " " << N << " " << P;
    return 0;
}