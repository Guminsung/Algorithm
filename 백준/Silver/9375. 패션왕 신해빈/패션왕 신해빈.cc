#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int cloth[30]; // 중복된 옷의 종류 개수를 저장하기 위한 배열
int cnt = 0;   // 옷의 종류 카운팅 변수

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    string name, type;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        unordered_map<string, int> tag; // 옷의 종류가 중복되는 지 확인하기 위한 공간
        int sm = 1;                     // 경우의 수 카운팅을 위한 변수
        cnt = 0;                        // 옷 종류 카운팅 변수 초기화
        for (int j = 0; j < n; j++)
            cloth[j] = 0; // 옷 종류에 따른 옷 개수 배열 초기화
        for (int j = 0; j < n; j++)
        {
            cin >> name >> type;
            if (tag.find(type) == tag.end())
            {
                cloth[cnt]++;
                tag[type] = cnt++; // 새 종류의 옷이라면 새로운 종류를 추가
            }
            else
                cloth[tag[type]]++; // 아니라면 기존 종류의 옷에 카운트 증가
        }
        for (int j = 0; j < n; j++)
            sm *= cloth[j] + 1; // 옷의 종류의 개수에 안 입는 경우까지 고려
        sm--;                   // 옷을 모두 안입는 경우를 제외
        cout << sm << "\n";
    }
    return 0;
}