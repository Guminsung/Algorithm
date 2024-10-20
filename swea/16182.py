t = int(input())
for tc in range(1, t+1):
    n = int(input())
    lst = [int(x) for x in input()]
    num = [0]*10
    mx = -1
    for l in lst:
        num[l] += 1
    for i in range(10):
        if mx <= num[i]:
            mx = num[i]
            idx = i
    print(f'#{tc} {idx} {mx}')
