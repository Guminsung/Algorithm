n = input()
for i in range(len(n)):
    print(ord(n[i])-64, end=' ')    # 문자에 해당하는 아스키코드를 받아와 정수로 계산
