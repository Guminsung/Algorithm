#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int i = (num - 1) / w;            // 꺼내려는 상자의 세로 위치
    int j;
    if (i % 2 == 0)
        j = (num - 1) % w;
    else                              // 꺼내려는 상자의 가로 위치
        j = (w - 1)  - ((num - 1) % w);
    int x = (n - 1) / w;              // 마지막 상자의 세로 위치
    if (x % 2 == 0)
    {
        int y = (n - 1) % w;
        if (y >= j)
            answer = x - i + 1;        // 마지막 상자의 세로 위치가 짝수일 때는 오른쪽 방향으로 채움
        else
            answer = x - i;
    }
    else
    {
        int y = (w - 1) - ((n - 1) % w);
        if (y <= j)
            answer = x - i + 1;        // 세로 위치가 홀수일 때는 왼쪽 방향으로 채움
        else
            answer = x - i;
    }
    return answer;
}
