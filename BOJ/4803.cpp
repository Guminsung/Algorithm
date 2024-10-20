#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> v(501);     // 노드의 연결 관계 저장
void treecheck(int s, int b);   // 트리 구별 함수 설정
bool visited[501];              // 방문한 노드인지를 구별하는 배열
bool cyc;                       // 사이클의 유무를 판별

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b, num = 1;
    while (1)
    {
        int cnt = 0;
        cin >> n >> m;
        if (n == 0 && m == 0)           // 0 0 입력이 들어올 때까지 출력 반복
            break;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            v[a].push_back(b);          // 입력값 2차원 벡터에 저장(연결 관계 판별)
            v[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)    // 각각의 노드를 탐색하여 트리 개수 탐색
            {
                treecheck(i, 0);
                if (cyc == false)       // 사이클이 없었을 시 트리이므로 갯수 +1
                    cnt++;
                else
                    cyc = false;        // 사이클 변수 초기화
            }
        }
        cout << "Case " << num << ": ";
        if (cnt > 1)
            cout << "A forest of " << cnt << " trees.\n";
        else if (cnt == 1)
            cout << "There is one tree.\n";         // 트리 개수에 따른 출력
        else
            cout << "No trees.\n";
        num++;
        for (int i = 1; i <= n; i++)
        {
            visited[i] = false;
            while (!v[i].empty())       // 한 타임 출력 완료 시 배열 모두 초기화
                v[i].pop_back();
        }
    }
    return 0;
}

void treecheck(int s, int b)        // 현 위치와 전 위치 호출
{
    visited[s] = true;          // 방문 노드 true로 변환
    for (int i = 0; i < v[s].size(); i++)
    {
        if (v[s][i] != b)       // 전 위치로 되돌아가는 경우 제외
        {
            if (visited[v[s][i]] == true)   // 방문한 노드 재방문 시 사이클 생성
                cyc = true;
            else
                treecheck(v[s][i], s);      // 사이클 미생성 시 다음 노드 탐색
        }
    }
}