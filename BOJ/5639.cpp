#include <iostream>
#include <vector>
using namespace std;
void Post(int s, int e);    // 후위 순회 함수 설정
int pre[10000];             // 전위 순회 입력값 저장 장소
int cnt = 0;                // 마지막 입력의 인덱스+1 표시

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int num;
    while (1)
    {
        cin >> num;
        if (cin.eof() == true)  // 입력이 끝날 때까지 계속 배열에 입력 저장
            break;
        pre[cnt++] = num;
    }
    Post(0, cnt);       // 후위 순회 함수 호출
    return 0;
}

void Post(int s, int e)     // 인덱스를 통해 탐색 범위 설정
{
    if (s < e)      // 종료 조건 설정
    {
        int temp = e;       // 반복문 동안 temp의 값을 찾지 못했을 경우, 범위 끝을 호출
        for (int i = s + 1; i < e; i++)
        {
            if (pre[s] < pre[i])
            {
                temp = i;       // 조건(왼쪽이 오른쪽 값보다 작음)에 부합하는 입력 탐색 시 입력의 인덱스 저장
                break;
            }
        }
        Post(s + 1, temp);      // 조건을 부합한 인덱스를 통해 분리 후 탐색
        Post(temp, e);
        cout << pre[s] << "\n"; // 후위 순회 출력
    }
}