#include <string>
#include <vector>

using namespace std;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1}; // 델타 탐색을 위한 위치 변수

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size(); // 보드의 길이 저장
    for (int i = 0; i < 4; i++)
    {
        int nx = h + dx[i], ny = w + dy[i]; // 다음 탐색 좌표 설정
        if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == board[h][w])
            answer++; // 같은 색을 찾으면 정답 +1
    }
    return answer;
}