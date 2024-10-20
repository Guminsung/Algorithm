def bs(s, e, f, c):                 # 이진탐색(binary search)를 재귀로 구현
    m = (s+e)//2
    if m == f:                      # 목표값을 찾으면 횟수 return
        return c+1
    elif m < f:                     # 중간값이 목표값보다 작을 때
        return bs(m, e, f, c+1)
    else:                           # 중간값이 목표값보다 클 때
        return bs(s, m, f, c+1)


t = int(input())
for tc in range(1, t+1):
    p, a, b = map(int, input().split()) # 이진 탐색 끝 값 밑 목표 지점 입력
    sa, ea, sb, eb = 1, p, 1, p     # a, b 이진 탐색 초기값 설정
    ca = bs(sa, ea, a, 0)       # a에 대한 binary search
    cb = bs(sb, eb, b, 0)       # b에 대한 binary search
    if ca == cb:                # a와 b의 도달 속도가 같을 때
        idx = '0'
    elif ca > cb:               # b가 a보다 빠를 때
        idx = 'B'
    else:                       # a가 b보다 빠를 때
        idx = 'A'
    print(f'#{tc} {idx}')
