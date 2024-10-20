for tc in range(1, 11):
    n = int(input())
    lst = list(map(int, input().split()))
    cnt = [0]*101
    for i in lst:
        cnt[i] += 1
    s, e = 0, 100
    while s < e:
        while cnt[e] == 0:
            e -= 1
        while cnt[s] == 0:
            s += 1
        if n == 0:
            break
        cnt[e] -= 1
        cnt[e-1] += 1
        cnt[s] -= 1
        cnt[s+1] += 1
        n -= 1
    print(f'#{tc} {e-s}')
