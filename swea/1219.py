def dfs(v):
    visited[v] = True
    lst = [nd1[v], nd2[v]]
    for w in lst:
        if w != -1 and not visited[w]:
            dfs(w)


for _ in range(1, 11):
    tc, n = map(int, input().split())
    arr = list(map(int, input().split()))
    nd1 = [-1] * 100
    nd2 = [-1] * 100
    visited = [False] * 100
    for i in range(n):
        x, y = arr[i * 2], arr[i * 2 + 1]
        if nd1[x] == -1:
            nd1[x] = y
        else:
            nd2[x] = y
    dfs(0)
    result = 1 if visited[99] else 0
    print(f'#{tc} {result}')
