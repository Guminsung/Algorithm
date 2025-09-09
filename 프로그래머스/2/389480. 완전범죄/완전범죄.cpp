#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int bag[121];                                // 냅색을 위한 배열

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    int sm = 0;                              // B가 훔친 물건의 A 흔적 합 저장 변수
    for (int i = 0;i < info.size();i++)
    {
        int v = info[i][0], w = info[i][1];  // A의 흔적을 가치, B의 흔적을 무게로 설정
        sm += v;                             // A의 흔적 합산
        for (int j = m;j > w;j--)
            bag[j] = max(bag[j], bag[j - w] + v);  // 해당 무게에 더 가치가 높은 것을 선택
    }
    sm -= max(bag[m], bag[m - 1]);           // 전체 A의 흔적에서 B가 가장 가치 있게 훔친만큼 제외
    if (sm < n)
        answer = sm;
    else                                     // A의 흔적 합이 n보다 높으면 조건 불만족이므로 -1 반환
        answer = -1;
    return answer;
}