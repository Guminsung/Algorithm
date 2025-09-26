#include <iostream>
#include <queue>

using namespace std;
int mn[200000]; // 각 위치의 최소 시간 저장 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, cnt = 0, mx = 1000000;   // 경우의 수와 가장 빠른 시간 저장 변수
    priority_queue<pair<int, int>> pq; // 가장 빠른 시간부터 탐색하기 위한 우선순위 큐
    cin >> n >> k;
    for (int i = 0; i < 200000; i++)
        mn[i] = mx;  // 각 위치 시간 초기화
    pq.push({0, n}); // 초기 값 입력
    while (!pq.empty())
    {
        int t = -pq.top().first, p = pq.top().second;
        pq.pop();
        if (p == k)
        {
            mx = t; // 목적지에 대한 최소 시간 갱신
            cnt++;
            continue;
        }
        if (mx < t)
            break; // 최종 최소 시간보다 오래 걸리는 정보는 제외
        if (p > 0 && mn[p - 1] >= t + 1)
        {
            mn[p - 1] = t + 1; // 위치에 대한 최소 시간보다 오래 걸리면 제외
            pq.push({-(t + 1), p - 1});
        }
        if (p < k)
        {
            if (mn[p + 1] >= t + 1)
            {
                mn[p + 1] = t + 1;
                pq.push({-(t + 1), p + 1});
            }
            if (mn[p * 2] >= t + 1)
            {
                mn[p * 2] = t + 1;
                pq.push({-(t + 1), p * 2});
            }
        }
    }
    cout << mx << "\n"
         << cnt;
    return 0;
}