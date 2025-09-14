#include <iostream>

using namespace std;
int graph[100][100]; // 플로이드 워셜 알고리즘을 위한 배열 설정

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    for (int k = 0; k < n; k++) // 정점 k를 중간 지점으로 설정 후 모든 공간 탐색
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1; // 정점 k를 통해 연결되어 있으면 1 입력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }
    return 0;
}