#include <iostream>
using namespace std;
pair<int, int> tree[26]; // 트리 구성할 배열 생성
void Pre(int idx); // 전위순회 함수 설정
void In(int idx); // 중위순회 함수 설정
void Post(int idx); // 후위순회 함수 설정

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    char c1, c2, c3;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> c1 >> c2 >> c3; // 부모 노드 및 자식 노드 2개 입력받기
        tree[(int)(c1 - 'A')] = make_pair((int)(c2 - 'A'), (int)(c3 - 'A')); // 문자열을 정수형으로 변형 및 부모 자식 노드 연결
    }
    Pre(0);
    cout << "\n";
    In(0);
    cout << "\n";
    Post(0);
    return 0;
}

void Pre(int idx) // 부모 노드 출력 후 자식 노드 탐색
{
    if (idx != -19) // '.'을 뜻하는 정수값일 때는 실행 X
    {
        cout << (char)(idx + 65); // 정수형을 다시 문자열로 변형 후 출력
        Pre(tree[idx].first); // 왼쪽 자식 노드 호출
        Pre(tree[idx].second); // 오른쪽 자식 노드 호출
    }
}

void In(int idx) // 왼쪽 자식 노드 탐색 완료 후 부모 노드 출력
{
    if (idx != -19)
    {
        In(tree[idx].first);
        cout << (char)(idx + 65);
        In(tree[idx].second);
    }
}

void Post(int idx) // 모든 자식 노드 탐색 완료 후 부모 노드 출력
{
    if (idx != -19)
    {
        Post(tree[idx].first);
        Post(tree[idx].second);
        cout << (char)(idx + 65);
    }
}