#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    sort(mats.begin(), mats.end());                   // 작은 돗자리부터 자리를 찾기 위해 오름차순 정렬
    for (int k = 0;k < mats.size();k++)
    {
        int m = mats[k];                              // 돗자리 한 변 길이 저장
        int px = park.size();                         // 공원의 세로 길이 저장
        for (int i = 0;i < park.size();i++)
        {
            int py = park[i].size();                  // 공원의 가로 길이 저장(직사각형이 아닐 수도 있으므로 내부에서 정의)
            for (int j = 0;j < park[i].size();j++)
                if (park[i][j] == "-1")
                {
                    bool check = true;                // 돗자리를 깔 수 있는지 확인하기 위한 변수
                    for(int x = 0;x < m;x++)
                    {
                        for(int y = 0;y < m;y++)
                            if (x + i >= px || y + j >= py || park[x + i][y + j] != "-1")
                            {
                                check = false;        // 공원의 범위를 벗어나거나 사람이 있는 경우 제외
                                break;
                            }
                        if (!check)
                            break;
                    }
                    if (check)
                        answer = m;                   // 돗자리를 깔 수 있으면 정답에 해당 돗자리의 한 변 길이 저장
                }
        }                 
    }
        
            
    return answer;
}