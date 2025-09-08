#include <string>
#include <vector>

using namespace std;

bool dfs(int x, int y);         // 출고 가능한지를 확인하는 함수 정의

bool check[52][52];             // 창고가 비었는지 확인하기 위한 공간
bool visited[52][52];           // dfs에서 탐색한 위치인지 확인하는 배열
vector<pair<int, int>> del;     // 출고할 컨테이너 위치 저장 공간
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // 상하좌우로 움직이기 위한 변수
int n, m;                       // 가로 세로 길이 할당 변수

int solution(vector<string> storage, vector<string> requests) {
    int answer = 0;
    n = storage.size(), m = storage[0].size();     // 초기 컨테이너의 가로 세로 길이를 변수에 할당
    for (int i = 1; i <= n;i++)
        for (int j = 1;j <= m;j++)                       // 초기 컨테이너 위치에 해당하는 창고를 채운다
            check[i][j] = true;
    for (int k = 0;k < requests.size();k++)
    {
        for (int i = 1; i <= n;i++)
            for (int j = 1;j <= m;j++)
                if (storage[i - 1][j - 1] == requests[k][0])
                {
                    if (requests[k].size() == 1)
                    {
                        for (int i = 1; i <= n;i++)
                            for (int j = 1;j <= m;j++)
                                visited[i][j] = false;
                        if (!dfs(i, j))
                            continue;
                    }
                    del.push_back(make_pair(i, j));  // 조건에 부합한 컨테이너 제거 준비
                }                   
        while (!del.empty())
        {
            int x = del.back().first, y = del.back().second;
            check[x][y]= false;                           // 출고할 컨테이너 창고에서 제외
            del.pop_back();
        }
    }
    for (int i = 1; i <= n;i++)
        for (int j = 1;j <= m;j++)
            if (check[i][j])                    // 남은 컨테이너 수를 카운트
                answer++;
    return answer;
}

bool dfs(int x, int y)
{
    if (x == 0 || y == 0 || x == n + 1 || y == m + 1)
        return true;
    visited[x][y] = true;
    for (int i = 0;i < 4;i++)
        if (!check[x + dx[i]][y + dy[i]] && !visited[x + dx[i]][y + dy[i]])
            if (dfs(x + dx[i], y + dy[i]))
                return true;
    return false;
}