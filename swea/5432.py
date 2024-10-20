t = int(input())
for tc in range(1, t+1):
    stick = input()
    cnt = 0                             # 누적 막대 갯수
    sm = 0                              # 합계
    i = 0                               # 인덱스
    while i < len(stick):               # 막대의 길이 동안 반복
        if stick[i] == '(':             # 레이저인지 막대 시작인지 구분
            if stick[i+1] == ')':       # 레이저면 누적된 막대의 개수 만큼 합계 증가
                sm += cnt
                i += 1                  # 레이저 부분 스킵
            else:                       # 막대 시작부분이면 막대 수 1개 증가 및 합계 1개 증가
                sm += 1
                cnt += 1
        else:                           # 막대 끝 부분이면 누적 막대 1개 감소
            cnt -= 1
        i += 1                          # 반복 인덱스 1개 증가
    print(f'#{tc} {sm}')
