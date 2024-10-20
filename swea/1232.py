def postorder(node):
    if not node:
        return
    if val[node] not in ['+', '-', '*', '/']:
        return int(val[node])
    a = postorder(cl[node])
    b = postorder(cr[node])
    if val[node] == '+':
        return a + b
    elif val[node] == '-':
        return a - b
    elif val[node] == '*':
        return a * b
    else:
        return a // b


for tc in range(1, 11):
    n = int(input())
    cl = [0] * (n + 1)
    cr = [0] * (n + 1)
    val = ['0'] * (n + 1)
    for _ in range(n):
        temp = list(input().split())
        idx = int(temp[0])
        val[idx] = temp[1]
        if len(temp) > 2:
            cl[idx] = int(temp[2])
            cr[idx] = int(temp[3])
    result = postorder(1)
    print(f'#{tc} {result}')
