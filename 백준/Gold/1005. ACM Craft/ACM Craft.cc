#include <iostream>
#include <vector>

using namespace std;

int dfs(int num);

vector<vector<int>> building(1001); // 각 건물 관계 노드
int build_time[1001];               // 건설 시간 저장 배열
bool check[1001];                   // 건설 시간 계산 완료 체크 배열

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, k, w, a, b;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            building[j].clear();
            check[j] = false; // 테스트케이스 시작 전 배열 초기화
        }
        cin >> n >> k;
        for (int j = 0; j < n; j++)
            cin >> build_time[j + 1]; // 각 건물의 건설 시간 저장
        for (int j = 0; j < k; j++)
        {
            cin >> a >> b;
            building[b].push_back(a); // b 건물을 짓는데 a 건물이 필요
        }
        cin >> w;
        cout << dfs(w) << "\n"; // 해당 건물의 최소 건설 시간 출력
    }
    return 0;
}

int dfs(int num)
{
    int mn = build_time[num]; // 건설 시간의 최솟값을 저장할 변수
    if (check[num])           // 건설 시간 계산이 완료된 건물이면 스킵
        return build_time[num];
    if (building[num].size() == 0) // 초기 건물이면 해당 건설 시간 반환
    {
        check[num] = true;
        return build_time[num];
    }
    for (int i = 0; i < building[num].size(); i++)
    {
        int temp = dfs(building[num][i]) + build_time[num];
        if (temp > mn) // 건설 시간이 가장 긴 값이 건물을 짓기 위해 필요한 시간의 최솟값
            mn = temp;
    }
    check[num] = true;    // 건설 시간 계산 완료 체크
    build_time[num] = mn; // 건설 시간 갱신
    return mn;
}