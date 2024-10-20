t = int(input())
for tc in range(1, t + 1):
    n, k = map(int, input().split())
    arr = input()
    num = []
    for i in range(n // 4):
        turn = arr[i:]
        turn += arr[0:i]
        sm = 0
        for j in range(0, n, n // 4):
            num.append(turn[j:j + n // 4])
    st_lst = sorted(list(set(num)))[::-1]
    result = int(st_lst[k - 1], 16)
    print(f'#{tc} {result}')
