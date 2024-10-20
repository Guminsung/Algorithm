dic = {
    '0': '0000', '1': '0001', '2': '0010', '3': '0011',
    '4': '0100', '5': '0101', '6': '0110', '7': '0111',
    '8': '1000', '9': '1001', 'A': '1010', 'B': '1011',
    'C': '1100', 'D': '1101', 'E': '1110', 'F': '1111',
}

dic2 = {
    (1, 1, 2): 0,
    (1, 2, 2): 1,
    (2, 2, 1): 2,
    (1, 1, 4): 3,
    (2, 3, 1): 4,
    (1, 3, 2): 5,
    (4, 1, 1): 6,
    (2, 1, 3): 7,
    (3, 1, 2): 8,
    (2, 1, 1): 9,
}

t = int(input())
for tc in range(1, t + 1):
    n, m = map(int, input().split())
    arr = [x for x in set(input().strip().strip('0') for _ in range(n)) if x]
    b_code = []
    f_code = []
    result = 0
    for i in arr:
        temp = ''
        for j in i:
            temp += dic[j]
        b_code.append(temp.rstrip('0'))
    for i in b_code:
        lst = []
        key = []
        cnt = 0
        j = len(i) - 2
        while j >= 0:
            cnt += 1
            if i[j] != i[j + 1]:
                lst.append(cnt)
                cnt = 0
            if len(lst) == 3:
                key.append(tuple(lst))
                lst = []
                while i[j] == '0':
                    j -= 1
            j -= 1
        if len(lst) > 0:
            lst.append(cnt + 1)
            key.append(tuple(lst))
        ln = len(key) // 8
        for th in range(0, ln):
            c_num = ''
            for idx in range(th * 8, (th + 1) * 8):
                d = min(key[idx])
                kv = tuple(map(lambda x: x // d, key[idx]))
                c_num += str(dic2[kv])
            f_code.append(c_num)
    f_code = list(set(f_code))
    for str_code in f_code:
        odd, even = 0, 0
        for idx in range(len(str_code)):
            if idx % 2 == 1:
                odd += int(str_code[idx])
            else:
                even += int(str_code[idx])
        if (odd * 3 + even) % 10 == 0:
            result += odd + even
    print(f'#{tc} {result}')
