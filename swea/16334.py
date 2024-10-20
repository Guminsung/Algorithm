t = int(input())
for tc in range(1, t+1):
    n, m = map(int, input().split())
    s = []
    for _ in range(n):
        s.append(input())
    print(f'#{tc}', end=' ')                        # 테스트케이스 번호 먼저 출력
    for i in range(n):
        for j in range(n-m+1):                      # 가로부터 탐색
            r = []
            rotate = True                           # 회문 여부 구분 변수
            for k in range(m):
                r.append(s[i][j+k])                 # 탐색할 문자열 다른 리스트에 저장
                if s[i][j+k] != s[i][j+m-k-1]:
                    rotate = False                  # 회문이 아닐 시 변수 False 대입
            if rotate == True:
                print(*r, sep='')                   # 회문이면 출력
                break
            r = []
            rotate = True
            for k in range(m):                      # 세로 탐색
                r.append(s[j+k][i])
                if s[j+k][i] != s[j+m-k-1][i]:      # 위와 동일
                    rotate = False
            if rotate == True:
                print(*r, sep='')
                break
