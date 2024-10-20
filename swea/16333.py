t = int(input())
for tc in range(1, t+1):
    s1 = input()                # 1번째 문자열 입력
    s2 = input()                # 2번째 문자열 입력
    print(f'#{tc}', end=' ')    # testcase 번호 출력
    if s1 in s2:                # s1이 s2에 속하면 '1' 출력 아니면 '0' 출력
        print('1')
    else:
        print('0')
