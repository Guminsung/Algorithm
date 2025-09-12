#include <iostream>
#include <string>

using namespace std;

void dfs(int x, int y);                           // dfs 탐색을 위해 함수 정의
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색을 위한 이동 배열
string campus[600];                               // 캠퍼스 정보를 받기 위한 문자열 배열
bool visited[600][600];                           // 방문 확인 배열
int n, m, cnt = 0;                                // 만날 수 있는 사람 수 카운팅

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, y;
    bool check = false; // 전역 변수가 아닐 때는 초기화 필수, 아니면 쓰레기값 들어감
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> campus[i];
    for (int i = 0; i < n; i++)
    {
        if (check)
            break; // 도연이를 찾았으면 반복문 종료
        for (int j = 0; j < m; j++)
            if (campus[i][j] == 'I')
            {
                x = i, y = j; // 도연이의 위치 탐색
                check = true;
                break;
            }
    }
    dfs(x, y);
    if (cnt > 0)
        cout << cnt;
    else
        cout << "TT";
    return 0;
}

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
            if (!visited[nx][ny] && campus[nx][ny] != 'X')
            {
                if (campus[nx][ny] == 'P')
                    cnt++;              // 사람 발견 시 카운트 증가
                visited[nx][ny] = true; // 방문 체크
                dfs(nx, ny);
            }
    }

}
