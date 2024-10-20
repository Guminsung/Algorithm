t = int(input())
for tc in range(1, t+1):
    s = input().strip()                 # 문자열 입력 시 strip() 함수를 통해 개행 제거
    l = len(s)                          # 문자열 길이를 변수에 대입
    rotate = True                       # 회문 문자 확인 변수
    for i in range(l):
        if s[i] != s[l-i-1]:            # 양 옆에서 비교하면서 다를 시 회문 변수에 False 할당
            rotate = False
    print(f'#{tc} {int(rotate)}')
