t = int(input())
for tc in range(1, t + 1):
    n = float(input())
    cnt = 0
    b = 1.0
    code = ''
    while cnt < 12:
        b /= 2
        if n >= b:
            n -= b
            code += '1'
        else:
            code += '0'
        cnt += 1
        if not n:
            break
    if n:
        code = 'overflow'
    print(f'#{tc} {code}')
