#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};                            // 델타 탐색을 위한 변수
unordered_map<string, int> delta = {{"N", 0}, {"W", 1}, {"S", 2}, {"E", 3}}; // 이동 방향 지정을 위한 해시맵

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int h = park.size(), w = park[0].size(); // 공원의 가로 세로 길이 저장
    int x, y;                                // 로봇 강아지의 위치 저장 변수
    
    for (int i = 0; i < h; i++)
    {
        bool check = false; // 강아지의 시작 지점을 찾았는지 체크하기 위한 변수
        for (int j = 0; j < w; j++)
            if (park[i][j] == 'S')
            {
                x = i, y = j;
                check = true; // 강아지의 시작 지점을 찾으면 반복문 종료
                break;
            }
        if (check)
            break;
    }
    
    for (int i = 0; i < routes.size(); i++)
    {
        bool pos = true;    // 이동 가능 여부 확인 변수
        int nx = x, ny = y; // 이동 전 위치 저장
        stringstream ss(routes[i]);
        string op, n;
        ss >> op >> n;
        for (int j = 1; j <= stoi(n); j++)
        {
            nx += dx[delta[op]], ny += dy[delta[op]]; // 정해진 방향으로 한 칸 씩 이동
            if (nx < 0 || nx >= h || ny < 0 || ny >= w || park[nx][ny] == 'X')
            {
                pos = false; // 공원을 벗어나거나 장애물에 막히면 이동 불가
                break;
            }
        }
        if (pos)
            x = nx, y = ny; // 이동 가능하다면 해당 위치로 이동
    }
    
    answer.push_back(x); // 마지막 강아지 위치 기입
    answer.push_back(y);
    return answer;
}