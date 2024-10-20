dy = [0, -1, 0, 1, 0]
dx = [0, 0, 1, 0, -1]
t = int(input())
for tc in range(1, t + 1):
    ax, ay = 1, 1
    bx, by = 10, 10
    M, A = map(int, input().split())
    ad = list(map(int, input().split()))
    bd = list(map(int, input().split()))
    bc = []
    sm = 0
    mx_a, mx_b = 0, 0
    for _ in range(A):
        bc.append(list(map(int, input().split())))
    for j in range(A):
        if abs(ax - bc[j][0]) + abs(ay - bc[j][1]) <= bc[j][2]:
            if bc[j][3] > mx_a:
                mx_a = bc[j][3]
        if abs(bx - bc[j][0]) + abs(by - bc[j][1]) <= bc[j][2]:
            if bc[j][3] > mx_b:
                mx_b = bc[j][3]
    sm += mx_a + mx_b
    for i in range(M):
        ax += dx[ad[i]]
        ay += dy[ad[i]]
        bx += dx[bd[i]]
        by += dy[bd[i]]
        tm_a = []
        tm_b = []
        for j in range(A):
            if abs(ax - bc[j][0]) + abs(ay - bc[j][1]) <= bc[j][2]:
                tm_a.append((bc[j][3], j))
        for j in range(A):
            if abs(bx - bc[j][0]) + abs(by - bc[j][1]) <= bc[j][2]:
                tm_b.append((bc[j][3], j))
        tm_a.sort()
        tm_b.sort()
        if tm_a and tm_b:
            if tm_a[-1][1] == tm_b[-1][1]:
                if len(tm_a) > 1 and len(tm_b) > 1:
                    if tm_a[-2][0] > tm_b[-2][0]:
                        tm_a.pop()
                    else:
                        tm_b.pop()
                elif len(tm_a) > len(tm_b):
                    tm_a.pop()
                elif len(tm_a) < len(tm_b):
                    tm_b.pop()
                else:
                    tm_a.append((0, 0))
            sm += tm_a[-1][0] + tm_b[-1][0]
        elif tm_a:
            sm += tm_a[-1][0]
        elif tm_b:
            sm += tm_b[-1][0]
    print(f'#{tc} {sm}')
