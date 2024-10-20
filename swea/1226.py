di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]
for _ in range(10):
    tc = int(input())
    arr = [list(input()) for _ in range(16)]
    q = []
    is_find = False
    for i in range(16):
        for j in range(16):
            if arr[i][j] == '2':
                q.append((i, j))
    while q and not is_find:
        for _ in range(len(q)):
            i, j = q.pop(0)
            for k in range(4):
                if 0 <= i + di[k] < 100 and 0 <= j + dj[k] < 100:
                    if arr[i + di[k]][j + dj[k]] == '0':
                        q.append((i + di[k], j + dj[k]))
                        arr[i + di[k]][j + dj[k]] = '-1'
                    elif arr[i + di[k]][j + dj[k]] == '3':
                        is_find = True
                        break
    if is_find:
        print(f'#{tc} 1')
    else:
        print(f'#{tc} 0')