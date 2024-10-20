A = [chr(ch) for ch in range(97, 123)]
t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    arr = []
    cnt = 0
    for _ in range(n):
        arr.append(input())
    for i in range(1 << n):
        lst = []
        for j in range(n):
            if i & (1 << j):
                lst.append(arr[j])
        word = ''.join(lst)
        for ch in A:
            if ch not in word:
                break
        else:
            cnt += 1
    print(f'#{tc} {cnt}')
