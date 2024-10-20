for _ in range(1, 11):
    tc = int(input())
    arr = [list(map(int, input().split()))
           for _ in range(100)]  # 100×100 배열 요소 입력
    mx = 0
    for i in range(100):
        sm = 0
        for j in range(100):
            sm += arr[i][j]     # 가로 합
        if mx < sm:
            mx = sm
    for i in range(100):
        sm = 0
        for j in range(100):
            sm += arr[j][i]     # 세로 합
        if mx < sm:
            mx = sm
    sm = 0
    for i in range(100):
        sm += arr[i][i]     # 우하향 대각선
    if mx < sm:
        mx = sm
    sm = 0
    for i in range(100):
        sm += arr[i][99-i]     # 좌하향 대각선
    if mx < sm:
        mx = sm
    print(f'#{tc} {mx}')
