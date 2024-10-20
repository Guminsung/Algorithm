#include <iostream>
using namespace std;
void preorder(int s, int e, int cnt);	// 전위 순회 함수 선언
int In[100000];		// 중위 순회 입력값 저장 장소
int Post[100000];	// 후위 순회 입력값 저장 장소
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;		// 중위 순회 입력값 저장
		In[i] = num;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;		// 후위 순회 입력값 저장
		Post[i] = num;
	}
	preorder(0, n - 1, 0);	// 전위 순회 함수 호출
	return 0;
}

void preorder(int s, int e, int cnt)	// 인덱스를 통해 찾을 범위와 후위 순회와 중위 순회의 인덱스 차이 호출
{
	if (s <= e)		// 종료 조건 선언
	{
		cout << Post[e - cnt] << " ";	// 전위 순회 출력
		for (int i = e; i >= s; i--)
		{
			if (Post[e - cnt] == In[i])		// 후위 순회값과 동일한 값을 중위 순회에서 탐색
			{
				preorder(s, i - 1, cnt);		// 중위 순회 인덱스를 기준으로 분리 후 각각 탐색
				preorder(i + 1, e, cnt + 1);
				break;
			}
		}
	}
}