while True:
    lst = list(input().split())
    if lst == '#':
        break
    a,b=0,0
    for i in lst:
        if i == '*':
            break
        elif i == 'A':
            a += 1
        elif int(i) % 2 == 0:
            b += 1
        else:
            a += 1
    if a > b:
        print('Cheryl')
    elif a < b:
        print('Tania')
    else:
        print('Draw')