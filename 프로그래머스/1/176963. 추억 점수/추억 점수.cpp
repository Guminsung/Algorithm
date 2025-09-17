#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    unordered_map<string, int> score;
    for (int i = 0; i < name.size(); i++)
        score[name[i]] = yearning[i]; // 해시맵에 이름에 해당하는 그리움 점수 저장
    for (int i = 0; i < photo.size(); i++)
    {
        int sm = 0; // 그리움 점수 합계 저장 변수
        for (int j = 0; j < photo[i].size(); j++)
            sm += score[photo[i][j]]; // 해당 이름의 그리움 접수 합산
        answer.push_back(sm);
    }
    return answer;
}