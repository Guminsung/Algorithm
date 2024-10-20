t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    arr = list(map(int, input().split()))
    mx = -1
    for i in range(len(arr) - 1):
        for j in range(i + 1, len(arr)):
            temp = arr[i] * arr[j]
            mul = temp
            md = temp % 10
            is_inc = True
            while temp:
                temp //= 10
                if md < temp % 10:
                    is_inc = False
                    break
                md = temp % 10
            if is_inc and mul > mx:
                mx = mul
    print(f'#{tc} {mx}')
