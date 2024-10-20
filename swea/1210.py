for _ in range(10):
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(100)]
    for i in range(len(arr[99])):
        if arr[99][i] == 2:                 # 끝 행에서 도착 지점 먼저 저장
            idx = i
    x = 99                                  # 출발 열 변수 지정
    while x > 0:
        if idx - 1 >= 0 and arr[x][idx - 1] == 1:
            while idx - 1 >= 0 and arr[x][idx - 1] != 0:
                idx -= 1                                    # 왼쪽이 사다리와 연결되어있을 경우, 연결된 부분 끝까지 이동
        elif idx + 1 <= 99 and arr[x][idx + 1] == 1:
            while idx + 1 <= 99 and arr[x][idx + 1] != 0:
                idx += 1                                    # 오른쪽이 사다리와 연결되어있을 경우, 연결된 부분 끝까지 이동
        x -= 1                                              # 사다리 타고 올라가기
    print(f'#{n} {idx}')
