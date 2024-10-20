di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]


def st_break(lst, cnt):
    global n, w, h
    if cnt == n:
        result = 0
        for i in range(h):
            for j in range(w):
                if lst[i][j]:
                    result += 1
        return result
    mn = 180
    for j in range(w):
        temp = [a[:] for a in lst]
        for i in range(h):
            if temp[i][j]:
                dfs(i, j, temp)
                gravity(temp)
                break
        sm = st_break(temp, cnt + 1)
        if mn > sm:
            mn = sm
    return mn


def dfs(i, j, temp):
    value = temp[i][j]
    temp[i][j] = 0
    for k in range(4):
        ci, cj = i, j
        for _ in range(1, value):
            ci += di[k]
            cj += dj[k]
            if 0 <= ci < h and 0 <= cj < w:
                dfs(ci, cj, temp)


def gravity(temp):
    for y in range(w):
        block = []
        for x in range(h):
            if temp[x][y]:
                block.append(temp[x][y])
                temp[x][y] = 0
        for x in range(h - 1, h - len(block) - 1, -1):
            temp[x][y] = block.pop()


t = int(input())
for tc in range(1, t + 1):
    n, w, h = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(h)]
    mx_cnt = st_break(arr, 0)
    print(f'#{tc} {mx_cnt}')
