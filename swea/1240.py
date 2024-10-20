dic = {
    '0001101': 0,
    '0011001': 1,
    '0010011': 2,
    '0111101': 3,
    '0100011': 4,
    '0110001': 5,
    '0101111': 6,
    '0111011': 7,
    '0110111': 8,
    '0001011': 9,
}

t = int(input())
for tc in range(1, t + 1):
    n, m = map(int, input().split())
    arr = [input() for _ in range(n)]
    is_find = False
    code = ''
    even = 0
    odd = 0
    for i in range(n):
        for j in range(m - 1, -1, -1):
            if arr[i][j] == '1':
                code = arr[i][j - 55:j + 1]
                is_find = True
                break
        if is_find:
            break
    for i in range(0, 56, 7):
        if i % 2 == 0:
            odd += dic[code[i:i + 7]]
        else:
            even += dic[code[i:i + 7]]
    if (odd * 3 + even) % 10 == 0:
        result = odd + even
    else:
        result = 0
    print(f'#{tc} {result}')