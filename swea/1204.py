t = int(input())

for tc in range(t):
    n = int(input())
    lst = list(map(int,input().split()))
    score = [0]*101
    mx = -1
    for i in lst:
        score[i] += 1
    for num in range(101):
        if mx <= score[num]:
            mx = score[num]
            idx = num
    print(f'#{n} {idx}')