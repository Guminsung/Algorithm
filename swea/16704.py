def sm_tree(lv, n):
    if lv > n:
        return 0
    if tree[lv] != 0:
        return tree[lv]
    tree[lv] = sm_tree(lv * 2, n) + sm_tree(lv * 2 + 1, n)
    return tree[lv]


t = int(input())
for tc in range(1, t + 1):
    n, m, l = map(int, input().split())
    tree = [0] * (n + 1)
    for _ in range(m):
        node, val = map(int, input().split())
        tree[node] = val
    sm_tree(1, n)
    print(f'#{tc} {tree[l]}')
