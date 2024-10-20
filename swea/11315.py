t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    arr = [list(input()) for _ in range(n)]
    arr2 = list(map(list, zip(*arr)))
    is_five = False
    for i in range(n):
        for j in range(n - 4):
            if arr[i][j:j + 5] == ['o'] * 5 or arr2[i][j:j + 5] == ['o'] * 5:
                is_five = True
                break
        if is_five:
            break
    for i in range(n - 4):
        for j in range(n - 4):
            lst, lst2 = [], []
            for k in range(5):
                lst.append(arr[i + k][j + k])
                lst2.append(arr[i + 4 - k][j + k])
            if lst == ['o'] * 5 or lst2 == ['o'] * 5:
                is_five = True
                break
        if is_five:
            break
    result = 'YES' if is_five else 'NO'
    print(f'#{tc} {result}')
