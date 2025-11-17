#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L;
    cin >> N >> L;

    deque<pair<int,int>> dq; // (값, 인덱스)
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;

        while (!dq.empty() && dq.back().first > a) dq.pop_back();
        dq.emplace_back(a, i);

        while (!dq.empty() && dq.front().second <= i - L) dq.pop_front();

        cout << dq.front().first << ' ';
    }
    return 0;
}