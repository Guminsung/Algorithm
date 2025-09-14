#include <iostream>
#include <string>

using namespace std;
int pi[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cnt = 0, ans = 0; // 일치 패턴과 Pn의 개수 카운팅 변수
    string s, p = "";
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
        p += "IO";
    p += "I"; // Pn 저장
    for (int i = 2; i < n * 2 + 1; i++)
        pi[i] = i - 1; // KMP 알고리즘을 위해 pi배열 생성
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1]; // 패턴이 다를 시, pi배열을 통해 건너뛰기
        if (s[i] == p[j])
            if (j == n * 2)
            {
                ans++;    // 패턴이 모두 같으면 Pn 카운트 증가
                j = pi[j]; // 겹치는 패턴 건너뛰기
            }
            else
                j++; // 패턴이 모두 같을 때까지 한칸씩 비교
    }
    cout << ans;
    return 0;
}