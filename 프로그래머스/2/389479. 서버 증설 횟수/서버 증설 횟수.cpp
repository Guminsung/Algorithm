#include <string>
#include <vector>

using namespace std;
int server[24] ={ 0 };       // 현재 증설된 서버 수 할당 배열

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for (int i = 0;i < 24;i++)
        if (players[i] / m > server[i])              // 서버가 감당할 인원 수를 넘었을 때
        {
            int dif = players[i] / m - server[i];    // 필요한 서버 수 계산
            answer += dif;
            for (int j = 0;j < k;j++)
            {
                if (i + j >= 24)                     // 범위를 넘어가면 정지
                    break;
                server[i + j] += dif;                // 운영 시간동안 서버 증설
            }
        }
    return answer;
}
