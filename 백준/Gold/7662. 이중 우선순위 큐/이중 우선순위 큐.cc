#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, k, num;
    char c;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        multiset<int> q; // 자동 정렬되는 Q
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> c >> num;
            if (c == 'I')
                q.insert(num); // I면 Q에 숫자 저장
            else
            {
                if (q.size() == 0)
                    continue; // Q가 비었으면 연산 무시
                if (num == 1)
                    q.erase(--q.end()); // 'D 1'이면 최댓값 삭제
                else
                    q.erase(q.begin()); // 'D -1'이면 최솟값 삭제
            }
        }
        if (q.size() == 0)
            cout << "EMPTY" << "\n";
        else
            cout << *q.rbegin() << " " << *q.begin() << "\n";
    }
    return 0;
}