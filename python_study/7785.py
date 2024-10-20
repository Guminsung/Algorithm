from sys import stdin

dct = {}
lst = []
n = int(input())
for _ in range(n):
    name, io = stdin.readline().split()
    if io == 'enter':
        dct[name] = 'leave'
    else:
        dct[name] = 'enter'

for k, v in dct.items():
    if v == 'leave':
        lst.append(k)
new_lst = sorted(lst, reverse=True)

for name in new_lst:
    print(name)