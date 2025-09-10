#include <iostream>

using namespace std;
int dp[1001]; // 동적 프로그래밍을 위한 배열 할당

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 3; // 동적 프로그래밍 시작 전 기본값
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 2] * 2 + dp[i - 1]; // 규칙에 맞게 바텀업 방식으로 전개
        dp[i] %= 10007;
    }
    cout << dp[n];
    return 0;
}