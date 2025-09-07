#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <set>

using namespace std;

int NtoTen(string num, int n);  // N진수에서 10진수로 변환하는 함수 선언
string TentoN(int num, int n);  // 10진수에서 N진수로 변환하는 함수 선언

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<string> sol;  // 진법을 유추할 수 있는 수식은 따로 저장
    vector<int> ans_format; // 가능한 진법 저장 공간
    int min_format = 2;  // 최소 진법 변수 설정
    for (int i = 0;i < expressions.size();i++)
    {
        string a, b, sign, equal, c;         // 수식의 구성 요소 변수 할당
        stringstream ss(expressions[i]);
        ss >> a >> sign >> b >> equal >> c;  // 수식을 분할
        
        for (int j = 0;j < a.size();j++)
        {
            int num = a[j] - '0' + 1;
            if (min_format < num)          // 각각의 수에 자릿수보다 큰 진법만 가능함
                min_format = num;
        }
        for (int j = 0;j < b.size();j++)
        {
            int num = b[j] - '0' + 1;
            if (min_format < num)
                min_format = num;
        }
        if (c == "X")
            answer.push_back(expressions[i]);  // C가 X일 때, 결과로 출력할 것이므로 정답 벡터에 저장
        else
        {
            sol.push_back(expressions[i]);  // C가 X가 아니라면, 진법 유추를 위한 벡터에 저장
            for (int j = 0;j < c.size();j++)
            {
                int num = c[j] - '0' + 1;
                if (min_format < num)
                    min_format = num;
            }
        }     
    }
    
    for (int i = min_format;i < 10;i++)
    {
        bool check = true;               // 수식이 해당 진법에서 성립하는 지 체크하는 변수
        for (int j = 0;j < sol.size();j++)
        {
            string a, b, sign, equal, c;
            stringstream ss(sol[j]);
            ss >> a >> sign >> b >> equal >> c;
            int A = NtoTen(a, i), B = NtoTen(b, i), C = NtoTen(c, i);
            if ((sign == "+" && A + B != C) || (sign == "-" && A - B != C))
            {
                check = false;           // 해당 진법에서 수식이 성립하지 않을 경우 체크
                break;
            }
        }
        if (check)
            ans_format.push_back(i);
    }
    
    for (int i = 0; i < answer.size();i++)
    {
        string a, b, sign, equal, c;
        stringstream ss(answer[i]);
        ss >> a >> sign >> b >> equal >> c;
        set<string> st;  // 가능한 진법으로 계산한 결과가 각각 다르게 나오는지 확인하기 위한 공간
        int temp;
        for (int j = 0;j < ans_format.size();j++)
        {
            int n = ans_format[j];
            int A = NtoTen(a, n), B = NtoTen(b, n);
            if (sign == "+")
                temp = A + B;
            else
                temp = A - B;            // 가능한 진법으로 계산 후 결과를 저장
            c = TentoN(temp, n);
            st.insert(c);
        }
        
        if (st.size() == 1)
            answer[i] = a + " " + sign + " " + b + " = " + c;     // 결과값이 다수이면 ?, 하나면 나온 결과값을 출력
        else
            answer[i] = a + " " + sign + " " + b + " = ?";
    }
    
    return answer;
}

int NtoTen(string num, int n)
{
    int result = 0;
    for (int i = 0;i < num.size(); i++)
        result += (num[i] - '0') * pow(n, num.size() - i - 1);  // 각 자리수에 자리 위치만큼 n을 제곱하여 더함
    return result;
}

string TentoN(int num, int n)
{
    string rev_n = "", result = "";
    if (num == 0)
        rev_n = "0";
    else
        while (num)
        {
            int temp = num % n;
            rev_n += to_string(temp);       // 뒷 자리부터 진법으로 계산된 값을 하나씩 추출
            num /= n;
        }
        for (int i = 0;i < rev_n.size();i++)
            result += rev_n[rev_n.size() - i - 1];   // 거꾸로 된 진법을 다시 원상복구
    return result;
}