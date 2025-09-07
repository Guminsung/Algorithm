#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0;i < schedules.size();i++)
    {
        int due = schedules[i] + 10;  // 마지노선 설정
        bool check = true;          // 정상 출근 체크 변수
        if (due % 100 >= 60)
            due += 40;              // 60분이 넘어갈 시 1시간으로 치환
        for (int j = 0;j < 7;j++)
        {
            int d = startday + j;            // 현재 요일 체크 변수
            if (d % 7 == 6 || d % 7 == 0)
                continue;                    // 주말은 제외
            if (timelogs[i][j] > due)
            {
                check = false;               // 지각 체크
                break;
            }
        }
        if (check)
            answer++;               // 평일 정상 출근 완료 시 직원 수 증가
    }
    return answer;
}