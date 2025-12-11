#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, a, b, u, v;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> a >> b;
        while (n--)
            cin >> u >> v;
        // 부품 관리 문구 출력
        cout << "Material Management " << i << "\n";
        // 프로그램 완료 문구 출력
        cout << "Classification ---- End!" << "\n";
    }
    return 0;
}