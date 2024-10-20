t = int(input())
for tc in range(1, t+1):
    s = input().strip()
    lst = []
    print(f'#{tc}', end=' ')
    for i in range(len(s)):
        if s[i] == '(':               # 스택에 '(' 삽입
            lst.append(1)
        if s[i] == '{':               # 스택에 '{' 삽입
            lst.append(2)
        if s[i] == ')':
            if len(lst) == 0:   # 스택이 비어 있을 경우 쓰레기값 삽입 후 반복문 종료
                lst.append(3)
                break
            elif lst.pop() != 1:     # ')' 발견 시 스택 제일 끝 부분이 '('인지 확인 후 맞으면 스택에서 '(' pop, 아니면 반복문 종료
                lst.append(3)
                break
        if s[i] == '}':
            if len(lst) == 0:   # 스택이 비어 있을 경우 쓰레기값 삽입 후 반복문 종료
                lst.append(3)
                break
            elif lst.pop() != 2:    # '}' 발견 시 스택 제일 끝 부분이 '{'인지 확인 후 맞으면 스택에서 '{' pop, 아니면 반복문 종료
                lst.append(3)
                break
    if len(lst) != 0:
        print(0)                # 스택에 값이 남아 있을 경우 짝을 다 못지었다는 뜻이므로 0 출력
    else:
        print(1)                # 짝을 다 이뤘으므로 1 출력
    print()