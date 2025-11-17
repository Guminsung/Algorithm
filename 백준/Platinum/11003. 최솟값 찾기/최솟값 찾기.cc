#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, A;
    cin >> n >> l;
    // 최솟값과 번호 저장 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++)
    {
        cin >> A;
        pq.push({A, i});
        int idx = pq.top().second; // 큐에 저장된 수의 번호 할당
        while (idx <= i - l)
        {
            pq.pop();
            idx = pq.top().second; // 범위 밖 수 모두 큐에서 방출
        }
        int a = pq.top().first; // 최솟값 할당
        cout << a << " ";
    }
    return 0;
}