#include <iostream>

using namespace std;
int rel[101][101]; // 플로이드 워셜 알고리즘을 위한 2차원 배열
int INF = 50000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, a, b, mn = INF, idx; // 최소 케빈 베이컨 수와 그에 해당하는 번호 저장 변수
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i == j)
                rel[i][j] = 0;
            else
                rel[i][j] = INF; // 초기에는 모두 못 만나게 INF값 대입
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        rel[a][b] = 1; // 가장 근접한 친구 관계 입력
        rel[b][a] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) // 플로이드 워셜 알고리즘을 통해 관계 갱신
                if (rel[i][j] > rel[i][k] + rel[k][j])
                    rel[i][j] = rel[i][k] + rel[k][j];
    for (int i = 1; i <= n; i++)
    {
        int sm = 0; // 케빈 베이컨 수를 저장할 변수
        for (int j = 1; j <= n; j++)
            sm += rel[i][j]; // i번의 친구 관계를 모두 합산
        if (sm < mn)
        {
            mn = sm; // 최소 케빈 베이컨 수라면 해당 값과 그 사람의 번호를 저장
            idx = i;
        }
    }
    cout << idx;
    return 0;
}