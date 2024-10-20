t = int(input())
arr = []
for tc in range(1, t + 1):
    a, b, c, d = map(int, input().split())
    is_true = True
    if not b and not c and a and d:
        is_true = False
    elif abs(b - c) >= 2:
        is_true = False
    if is_true:
        if not b and not c:
            if a:
                result = '0' * (a + 1)
            else:
                result = '1' * (d + 1)
        elif b >= c:
            result = '0' * a + '01' * b + '1' * d
            if b == c:
                result = '0' * a + '01' * b + '1' * d + '0'
        else:
            result = '1' * d + '10' * c + '0' * a
    else:
        result = 'impossible'
    arr.append(result)
for tc in range(1, t + 1):
    print(f'#{tc} {arr[tc - 1]}')
