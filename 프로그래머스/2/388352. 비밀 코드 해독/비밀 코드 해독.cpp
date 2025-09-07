#include <string>
#include <vector>

using namespace std;

void dfs(int k, int n, vector<int> seq);
vector<vector<int>> mix;     // 5가지 수에 대한 모든 조합을 저장할 공간

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int> temp;
    
    dfs(1, n, temp);            // 모든 조합을 탐색
    
    for (int i = 0;i < mix.size();i++)
    {
        bool check = true;                      // 시스템 응답과 같은 결과인지 확인하기 위한 변수
        
        for (int j = 0;j < q.size();j++)
        {
            int cnt = 0;                        // 비밀 코드에 포함된 정수의 개수 카운트
            for (int a = 0;a < 5;a++)
                for (int b = 0;b < 5;b++)
                    if (mix[i][a] == q[j][b])
                        cnt++;                 // 코드에 포함된 수를 찾으면 카운트 증가
            
            if (cnt != ans[j])
            {
                check = false;                  // 시스템 응답과 다르면 바로 제외
                break;
            }
        }
        
        if (check)                              // 시스템 응답과 같으면 정수 조합 개수 카운트 증가
            answer++;
    }
    return answer;
}

void dfs(int k, int n, vector<int> seq)
{
    if (seq.size() == 5)                  // 5가지 수로 조합했다면 2차원 벡터에 저장
        mix.push_back(seq);
    else
        for (int i = k; i <= n;i++)
        {
            seq.push_back(i);
            dfs(i + 1, n, seq);           // 앞의 수들보다 더 큰 수들 중 하나를 조합
            seq.pop_back();
        }
}