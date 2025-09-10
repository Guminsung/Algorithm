#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string num = "";  // 영단어가 숫자로 변환된 문자열을 저장할 변수
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'z')
        {
            num += "0";
            i += 3;
        }
        else if (s[i] == 'o')
        {
            num += "1";
            i += 2;
        }
        else if (s[i] == 't')
        {
            if (s[i + 1] == 'w')   // 각 영단어에 해당하는 숫자 문자열로 대입 후 영단어 스펠링만큼 건너뛰기
            {
                num += "2";
                i += 2;
            }
            else
            {
                num += "3";
                i += 4;
            }
        }
        else if (s[i] == 'f')
        {
            if (s[i + 1] == 'o')
            {
                num += "4";
                i += 3;
            }
            else
            {
                num += "5";
                i += 3;
            }
        }
        else if (s[i] == 's')
        {
            if (s[i + 1] == 'i')
            {
                num += "6";
                i += 2;
            }
            else
            {
                num += "7";
                i += 4;
            }
        }
        else if (s[i] == 'e')
        {
            num += "8";
            i += 4;
        }
        else if (s[i] == 'n')
        {
            num += "9";
            i += 3;
        }
        else
            num += s[i];
    }
    answer = stoi(num);
    return answer;
}