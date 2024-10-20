def search_home(x, y, k, n):
    c = 0
    for dx in range(k):
        for dy in range(k - dx):
            if 0 <= x + dx < n and 0 <= y + dy < n:
                if arr[x + dx][y + dy]:
                    c += 1
            if 0 <= x + dx < n and 0 <= y - dy < n:
                if arr[x + dx][y - dy] and dy:
                    c += 1
            if 0 <= x - dx < n and 0 <= y + dy < n:
                if arr[x - dx][y + dy] and dx:
                    c += 1
            if 0 <= x - dx < n and 0 <= y - dy < n:
                if arr[x - dx][y - dy] and dx and dy:
                    c += 1
    return c


t = int(input())
for tc in range(1, t + 1):
    n, m = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(n)]
    cnt = 0
    for i in range(n):
        for j in range(n):
            if arr[i][j]:
                cnt += 1
    mx_cost = m * cnt
    mx_home = 0
    for k in range(1, 50):
        cost = k ** 2 + (k - 1) ** 2
        if cost > mx_cost:
            break
        for i in range(n):
            for j in range(n):
                temp = search_home(i, j, k, n)
                if temp * m >= cost and mx_home < temp:
                    mx_home = temp
    print(f'#{tc} {mx_home}')
