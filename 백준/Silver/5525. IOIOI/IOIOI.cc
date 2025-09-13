#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, cnt = 0; // Pn의 개수 카운트 변수
    string s, p = "";
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++)
        p += "IO";
    p += "I"; // Pn 저장
    for (int i = 0; i < m - n * 2 + 1; i++)
    {
        bool check = true;
        if (s[i] == 'I')
        {
            for (int j = 0; j < n * 2 + 1; j++)
                if (s[i + j] != p[j])
                {
                    check = false;
                    break;
                }
            if (check) // Pn을 찾았으면 카운트 증가
                cnt++;
        }
    }
    cout << cnt;
    return 0;
}