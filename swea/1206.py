pos = [-2, -1, 1, 2]
for i in range(1, 11):
    sm = 0
    n = int(input())
    lst = list(map(int, input().split()))
    for j in range(2, n-2):
        mx = -1
        for p in pos:
            if lst[j+p] > mx:
                mx = lst[j+p]
        if lst[j] > mx:
            sm += lst[j] - mx
    print(f'#{i} {sm}')
