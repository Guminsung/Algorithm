t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    arr = [list(map(int, list(input()))) for _ in range(n)]
    sm = 0
    for i in range(n):
        x, y = abs((n // 2) - i), n - abs((n // 2) - i)
        sm += sum(arr[i][x:y])
    print(f'#{tc} {sm}')
