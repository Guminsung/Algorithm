#include <iostream>

using namespace std;
int dp[50001]; // dp를 위한 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, sq = 223; // 50000이하의 최대 제곱수의 밑
    cin >> n;
    for (int i = 1; i <= 50000; i++)
        dp[i] = 5; // 자연수가 최대 4개의 제곱수의 합으로 표현된다 하므로 5로 dp 배열 초기화
    for (int i = 1; i <= sq; i++)
        dp[i * i] = 1;          // 제곱수에 해당하는 수는 한 번에 만들어지므로 1 대입
    for (int k = 0; k < 3; k++) // 나머지 3번의 제곱수 덧셈을 계산
        for (int i = 1; i <= sq; i++)
            for (int j = 1; j <= n; j++)
                if (j - i * i > 0 && dp[j] > dp[j - i * i] + 1)
                    dp[j] = dp[j - i * i] + 1; // 더 적은 제곱수 덧셈으로 표현 가능한 경우 값을 변환
    cout << dp[n];
    return 0;
}