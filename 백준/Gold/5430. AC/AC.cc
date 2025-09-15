#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n;
    string p, x; // 배열과 함수를 string형으로 저장
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        deque<string> dq; // 배열을 저장할 덱 할당
        string temp = ""; // 배열 내의 정수를 추출할 변수
        cin >> p >> n >> x;
        for (int j = 0; j < x.size(); j++)
        {
            if (x[j] == '[')
                continue;
            if (x[j] == ',' || x[j] == ']' && temp != "")
            {
                dq.push_back(temp); // 정수 하나를 완성시키면 저장
                temp = "";          // 추출 변수 초기화
                continue;
            }
            temp += x[j]; // 정수 추출
        }
        bool f = true, err = false; // 추출 순서 확인과 에러 체크 변수
        for (int j = 0; j < p.size(); j++)
        {

            if (p[j] == 'R')
                f = !f; // 함수가 R일 때, 순서 뒤집기
            else
            {
                if (dq.empty())
                {
                    err = true; // 함수가 D인데 배열이 비어있으면 에러 체크 후 반복문 탈출
                    break;
                }
                if (f)
                    dq.pop_front(); // 순서가 앞이면 앞부터 제거
                else
                    dq.pop_back(); // 순서가 뒤면 뒤부터 제거
            }
        }
        if (err)
            cout << "error"; // 에러가 있을 시 error 출력
        else
        {
            int ln = dq.size();
            cout << "[";
            if (f)
                for (int j = 0; j < ln; j++)
                {
                    cout << dq.front();
                    dq.pop_front(); // 순서가 앞이면 앞부터 출력
                    if (j < ln - 1)
                        cout << ","; // 마지막은 콤마를 기입하지 않음
                }
            else
                for (int j = 0; j < ln; j++)
                {
                    cout << dq.back();
                    dq.pop_back(); // 순서가 뒤면 뒤부터 출력
                    if (j < ln - 1)
                        cout << ",";
                }
            cout << "]";
        }
        cout << "\n";
    }
    return 0;
}