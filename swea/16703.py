def heap(node):
    if node == 1:
        return
    if tree[node] < tree[node // 2]:
        tree[node], tree[node // 2] = tree[node // 2], tree[node]
    heap(node // 2)


t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    tree = [0]
    v_lst = list(map(int, input().split()))
    for i in range(n):
        tree.append(v_lst[i])
        heap(i + 1)
    sm = 0
    while n != 1:
        n //= 2
        sm += tree[n]
    print(f'#{tc} {sm}')
