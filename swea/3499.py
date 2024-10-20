t = int(input())
for tc in range(1, t + 1):
    n = int(input())
    deq = list(input().split())
    lst, lst2 = [], []
    for i in range(len(deq) // 2 + len(deq) % 2):
        lst.append(deq[i])
    for i in range(len(deq) // 2 + len(deq) % 2, len(deq)):
        lst2.append(deq[i])
    new_deq = []
    for i in range(len(lst2)):
        new_deq.append(lst[i])
        new_deq.append(lst2[i])
    if len(lst) > len(lst2):
        new_deq.append(lst[-1])
    print(f'#{tc}', *new_deq)
