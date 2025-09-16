#include <string>
#include <vector>
#include <set>

using namespace std;

int dfs(int x, int y);                            // 석유 덩어리 체크를 dfs 함수 정의
int oil[500][500];                                // 석유 덩어리 위치 저장 배열
int scale[250000];                                // 각 석유 덩어리의 크기 저장 배열
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색을 위한 변수
int num = 2;                                      // 석유 덩어리 번호를 표시하기 위한 변수
int n, m;                                         // 땅의 가로 세로 길이 저장 변수

int solution(vector<vector<int>> land) {
    int answer = 0;
    n = land.size(), m = land[0].size(); // 땅의 가로 세로 길이 저장
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            oil[i][j] = land[i][j]; // 석유 위치 저장
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (oil[i][j] == 1)
            {
                scale[num] = dfs(i, j); // dfs로 석유 덩어리 탐색 후 번호 매기기
                num++;
            }
    for (int j = 0; j < m; j++)
    {
        set<int> s; // 중복되지 않는 석유 덩어리 개수를 세기 위한 변수
        int sm = 0; // 석유 덩어리 크기 합 저장 변수
        for (int i = 0; i < n; i++)
            if (oil[i][j])
                s.insert(oil[i][j]); // 석유 덩어리 번호 저장
        for (auto it = s.begin(); it != s.end(); it++)
            sm += scale[*it]; // 석유 덩어리 크기 합산
        if (answer < sm)
            answer = sm; // 가장 많은 석유량을 저장
    }  
    return answer;
}

int dfs(int x, int y)
{
    int cnt = 1;     // 석유 덩어리 크기를 위한 변수
    oil[x][y] = num; // 석유 덩어리 번호 기입
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i]; // 다음 이동 위치 저장
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && oil[nx][ny] == 1)
            cnt += dfs(nx, ny); // 범위 내 석유 탐색
    }
    return cnt; // 석유 덩어리 크기 출력
}