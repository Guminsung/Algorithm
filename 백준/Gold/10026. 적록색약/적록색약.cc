#include <iostream>
#include <string>

using namespace std;
void dfs(int x, int y);                           // dfs 함수 정의
void dfs_cb(int x, int y);                        // 색약 dfs 함수 정의
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색을 위한 위치 변수
bool visited[100][100];                           // 탐색 유무 체크 배열
string rgb[100];                                  // 구역 색상 저장 배열
int n, cnt = 0, cnt_cb = 0;                       // 구역의 수 카운팅 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> rgb[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j])
            {
                cnt++; // 색약이 아닐 때 구역 카운팅
                dfs(i, j);
            }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j])
            {
                cnt_cb++; // 색약일 때 구역 카운팅
                dfs_cb(i, j);
            }
    cout << cnt << " " << cnt_cb;
    return 0;
}

void dfs(int x, int y)
{
    visited[x][y] = true; // 탐색 체크
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i]; // 다음 이동 좌표 설정
        if (nx >= 0 && nx < n && ny >= 0 && ny < n)
            if (!visited[nx][ny] && rgb[nx][ny] == rgb[x][y])
                dfs(nx, ny); // 범위 내에 탐색하지 않았으며 같은 색상으로 이동
    }
}

void dfs_cb(int x, int y)
{
    visited[x][y] = true; // 탐색 체크
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i]; // 다음 이동 좌표 설정
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny])
        {
            if (rgb[x][y] == 'R' || rgb[x][y] == 'G')
            {
                if (rgb[nx][ny] == 'R' || rgb[nx][ny] == 'G')
                    dfs_cb(nx, ny); // 빨강과 초록은 같은 색상 취급
            }
            else if (rgb[nx][ny] == rgb[x][y])
                dfs_cb(nx, ny); // 파랑은 그대로 진행
        }
    }
}