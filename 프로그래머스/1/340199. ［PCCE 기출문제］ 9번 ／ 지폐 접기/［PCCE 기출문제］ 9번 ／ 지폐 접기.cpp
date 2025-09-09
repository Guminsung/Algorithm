#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    int big, small;              // 지폐 길이가 어느 쪽이 더 긴지 저장
    if (bill[0] > bill[1])
    {
        big = bill[0];
        small = bill[1];
    }                            // 길이를 비교하여 변수에 저장
    else
    {
        big = bill[1];
        small = bill[0];
    }
    if (wallet[0] > wallet[1])
        while (big > wallet[0] || small > wallet[1])
        {
            answer++;
            big /= 2;
            if (small > big)
            {
                int temp = small;        // 조건을 만족할 때까지 계속 반으로 접기
                small = big;
                big = temp;
            }
        }
    else
        while (big > wallet[1] || small > wallet[0])
        {
            answer++;
            big /= 2;
            if (small > big)
            {
                int temp = small;
                small = big;
                big = temp;
            }
        }
    return answer;
}