def pmt(arr, i):
    global n
    if i == n:
        scale(arr, 0, 0, 0)
        return

    for j in range(i, n):
        arr[i], arr[j] = arr[j], arr[i]
        pmt(arr, i + 1)
        arr[j], arr[i] = arr[i], arr[j]


def scale(arr, i, left, right):
    global cnt, n, mx
    if i == n:
        cnt += 1
        return
    if left >= mx - left:
        cnt += 2 ** (n - i)
        return
    else:
        scale(arr, i + 1, left + arr[i], right)
        if left >= right + arr[i]:
            scale(arr, i + 1, left, right + arr[i])


t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    gram = list(map(int, input().split()))
    cnt = 0
    mx = sum(gram)
    pmt(gram, 0)
    print(f'#{tc} {cnt}')
