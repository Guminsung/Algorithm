t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    x = -1
    temp = 1
    while temp ** 3 <= n:
        if temp ** 3 == n:
            x = temp
        temp += 1
    print(f'#{tc} {x}')
