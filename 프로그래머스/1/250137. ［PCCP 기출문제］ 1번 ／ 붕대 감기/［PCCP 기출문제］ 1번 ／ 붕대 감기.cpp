#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;              // 현재 체력
    int cur = 0;                      // 현재 시간 변수
    int combo = bandage[0];           // 추가 회복을 위한 시전 시간
    int heal = bandage[1];            // 초당 회복량
    int extra = bandage[2];           // 추가 회복량
    for (int i = 0;i < attacks.size();i++)
    {
        int cnt = 0;                  // 연속 시간 체크 변수
        int t = attacks[i][0];        // 공격 시간 변수
        int dam = attacks[i][1];      // 데미지 변수
        for (int j = cur + 1;j < t;j++)
        {
            answer += heal;               // 초당 회복
            cnt++;                        // 연속 시간 체크
            if (cnt == combo)
            {
                answer += extra;          // 연속 시간 달성 시 추가 회복
                cnt = 0;
            }
            if (answer > health)
                answer = health;          // 현재 체력이 최대 체력보다 많을 시 리셋
        }
        answer -= dam;                    // 몬스터 공격
        if (answer <= 0)
        {
            answer = -1;                  // 캐릭터 사망 시 즉시 종료 및 -1 리턴
            break;
        }
        cur = t;                          // 현재 시간 동기화
    }  
    return answer;
}