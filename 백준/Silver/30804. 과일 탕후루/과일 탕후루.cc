#include <iostream>

using namespace std;
int tanghuru[200000]; // 과일 위치 저장 배열
int fruit[10];        // 현재 해당 과일 종류와 개수 파악 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, e, mx = 0; // 투 포인터와 최대값 저장 변수 할당
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> tanghuru[i]; // 탕후루 과일 위치 저장
    s = 0, e = 0;           // 초기 시작점 설정
    while (e <= n)
    {
        int cnt = 0;
        for (int j = 1; j < 10; j++)
            if (fruit[j] > 0)
                cnt++; // 현재 탕후루의 과일 종류 개수 파악
        if (cnt > 2)
        {
            fruit[tanghuru[s]]--; // 과일 종류 2가지 초과 시 탕후루 앞쪽부터 제외
            s++;
            continue;
        }
        if (mx < e - s)
            mx = e - s; // 최댓값 갱신
        if (e == n)     // 더 이상 탕후루가 없으므로 반복문 종료
            break;
        fruit[tanghuru[e]]++; // 탕후루 하나씩 추가
        e++;
    }
    cout << mx;
    return 0;
}