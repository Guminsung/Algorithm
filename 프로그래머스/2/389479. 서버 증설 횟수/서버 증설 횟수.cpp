#include <string>
#include <vector>

using namespace std;
int server[24] ={ 0 };       // 현재 증설된 서버 수 할당 배열

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    for (int i = 0;i < 24;i++)
        if (players[i] / m > server[i])
        {
            int dif = players[i] / m - server[i];
            answer += dif;
            for (int j = 0;j < k;j++)
            {
                if (i + j >= 24)
                    break;
                server[i + j] += dif;
            }
        }
    return answer;
}