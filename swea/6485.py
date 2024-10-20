t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    bus = [0] * 5001
    for _ in range(n):
        a, b = map(int, input().split())
        for i in range(a, b + 1):
            bus[i] += 1
    p = int(input())
    lst = []
    for _ in range(p):
        c = int(input())
        lst.append(bus[c])
    print(f'#{tc}', *lst)
