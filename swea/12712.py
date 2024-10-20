di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]
dx = [1, -1, 1, -1]
dy = [1, 1, -1, -1]
t = int(input())
for tc in range(1, t + 1):
    n, m = map(int, input().split())
    arr = [list(map(int, input().split())) for _ in range(n)]
    mx = -1
    for i in range(n):
        for j in range(n):
            sm_ij, sm_xy = arr[i][j], arr[i][j]
            for k in range(4):
                ni, nj = i, j
                nx, ny = i, j
                for _ in range(1, m):
                    ni += di[k]
                    nj += dj[k]
                    nx += dx[k]
                    ny += dy[k]
                    if 0 <= ni < n and 0 <= nj < n:
                        sm_ij += arr[ni][nj]
                    if 0 <= nx < n and 0 <= ny < n:
                        sm_xy += arr[nx][ny]
            if sm_ij > mx:
                mx = sm_ij
            if sm_xy > mx:
                mx = sm_xy
    print(f'#{tc} {mx}')
