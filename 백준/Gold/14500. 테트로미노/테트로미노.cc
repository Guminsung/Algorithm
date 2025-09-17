#include <iostream>

using namespace std;

void dfs(int x, int y, int sm, int dep);          // 테트로미노 모양 탐색을 위한 함수 정의
void extra(int x, int y);                         // dfs로 만들지 못하는 모양 처리 함수 정의
bool visited[500][500];                           // 방문 체크 배열
int tetro[500][500];                              // 종이에 적힌 수 저장 배열
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색을 위한 변수
int n, m, mx = 0;                                 // 최댓값 저장 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> tetro[i][j]; // 종이에 적힌 수 저장
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = true;  // 방문 위치 체크
            dfs(i, j, 0, 1);       // 해당 위치를 기점으로 탐색
            visited[i][j] = false; // 방문 해제
            extra(i, j);           // 나머지 모양도 탐색
        }
    cout << mx;
    return 0;
}

void dfs(int x, int y, int sm, int dep)
{
    sm += tetro[x][y]; // 해당값 합산
    if (dep == 4)
    {
        if (mx < sm) // 깊이가 4일 때 최댓값 비교 후 갱신, 탐색 종료
            mx = sm;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i]; // 다음 이동 위치 저장
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny])
        {
            visited[nx][ny] = true; // 방문 체크
            dfs(nx, ny, sm, dep + 1); // 범위 내 한 칸 이동
            visited[nx][ny] = false; // 방문 체크 해제
        }
            
    }
}

void extra(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int sm = tetro[x][y];
        bool check = true; // 해당 테트로미노가 가능한지 체크하기 위한 변수
        for (int j = 0; j < 3; j++)
        {
            int k = (i + j) % 4;
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                check = false; // 해당 테트로미노는 불가능한 모양
                break;
            }
            sm += tetro[nx][ny];
        }
        if (check && mx < sm)
            mx = sm; // 가능한 모양이고 합이 최대보다 클 때, 최댓값 갱신
    }
}