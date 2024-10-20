def card(level, s):
    if level == 6:
        lst.append(s)
        return
    for i in range(10):
        temp = s
        temp += str(i)
        card(level + 1, temp)


t = int(input())
for tc in range(1, t + 1):
    lst = []
    r = []
    final = []
    f_true = False
    card(0, '')
    num = input().strip()
    for i in range(len(lst)):
        cnt = [0] * 10
        is_cnt = 0
        for j in range(6):
            cnt[int(lst[i][j])] += 1
        for j in range(10):
            if cnt[j] == 3:
                is_cnt += 1
            if cnt[j] == 6:
                is_cnt += 2
        if is_cnt == 2:
            final.append(lst[i])
    for i in range(len(lst)):
        cnt = [0] * 10
        is_true = False
        for j in range(6):
            cnt[int(lst[i][j])] += 1
        for j in range(5):
            if cnt[j] and cnt[j + 1] and cnt[j + 2] and cnt[j + 3] and cnt[j + 4] and cnt[j + 5]:
                is_true = True
        if is_true:
            final.append(lst[i])
    for i in range(len(lst)):
        cnt = [0] * 10
        is_cnt = 0
        for j in range(6):
            cnt[int(lst[i][j])] += 1
        for j in range(7):
            if cnt[j] and cnt[j + 1] and cnt[j + 2]:
                cnt[j] -= 1
                cnt[j + 1] -= 1
                cnt[j + 2] -= 1
                is_cnt += 1
        for j in range(7):
            if cnt[j] and cnt[j + 1] and cnt[j + 2]:
                cnt[j] -= 1
                cnt[j + 1] -= 1
                cnt[j + 2] -= 1
                is_cnt += 1
        if is_cnt == 2:
            final.append(lst[i])
    for i in range(len(lst)):
        cnt = [0] * 10
        is_true = False
        for j in range(6):
            cnt[int(lst[i][j])] += 1
        for j in range(7):
            if cnt[j] and cnt[j + 1] and cnt[j + 2]:
                if cnt[j] == 4 or cnt[j + 1] == 4 or cnt[j + 2] == 4:
                    is_true = True
                for k in range(10):
                    if cnt[k] == 3 and k != j and k != j + 1 and k != j + 2:
                        is_true = True
        if is_true:
            final.append(lst[i])
    for ch in final:
        if ch == num:
            f_true = True
    if f_true:
        print(f'#{tc} true')
    else:
        print(f'#{tc} false')
