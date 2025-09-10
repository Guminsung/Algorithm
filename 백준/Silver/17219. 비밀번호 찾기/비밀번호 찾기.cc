#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    string address, password;
    unordered_map<string, string> note; // 해당 주소의 비밀번호를 저장할 해시맵 할당
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> address >> password;
        note[address] = password; // 해시맵 키를 주소로, 비밀번호를 값으로 입력
    }
    for (int i = 0; i < m; i++)
    {
        cin >> address;
        cout << note[address] << "\n"; // 해시맵에서 해당 주소의 값을 반환
    }
    return 0;
}