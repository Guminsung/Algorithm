lst = []
lst.append(0)
lst.append(1)
n = int(input())
for i in range(n):
    lst.append(lst[i] + lst[i + 1])
print(lst[n])
