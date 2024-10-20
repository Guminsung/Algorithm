def node_search(n):
    sum = 1
    if tree_l[n] != 0:
        sum += node_search(tree_l[n])
    if tree_r[n] != 0:
        sum += node_search(tree_r[n])
    return sum


t = int(input())
for tc in range(1, t + 1):
    e, n = map(int, input().split())
    lst = list(map(int, input().split()))
    tree_l = [0] * (e + 2)
    tree_r = [0] * (e + 2)
    for i in range(e):
        if tree_l[lst[i * 2]] == 0:
            tree_l[lst[i * 2]] = lst[i * 2 + 1]
        else:
            tree_r[lst[i * 2]] = lst[i * 2 + 1]
    cnt = node_search(n)
    print(f'#{tc} {cnt}')
