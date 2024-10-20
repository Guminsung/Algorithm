t = int(input())
for tc in range(1, t+1):
    n = int(input())
    lst = list(map(int, input().split()))       # 입력값 리스트에 저장
    lst.sort()                                  # 오름차순 정렬
    sp = []
    s, e = 0, n-1                               # 시작 인덱스와 종료 인덱스 설정
    while s < e and len(sp) < 10:               # 두 인덱스가 교차하기 전까지나 리스트에 요소가 10개가 저장되기 전까지 반복
        sp.append(lst[e])
        e -= 1                                  # 끝값부터 차례로 하나씩 리스트에 저장
        sp.append(lst[s])
        s += 1                                  # 시작값부터 차례로 하나씩 리스트에 저장
    print(f'#{tc}', *sp)
