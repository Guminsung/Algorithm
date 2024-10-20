for tc in range(1, 11):
    n = int(input())
    arr = [list(input()) for _ in range(8)]         # 2차원 배열 입력
    arr2 = list(map(list, zip(*arr)))               # 입력값의 전치 행렬 생성
    cnt = 0                                         # 회문 갯수 카운팅 변수
    for i in range(8):                              # 2차원 배열의 앞 쪽 인덱스 순회
        for j in range(8-n+1):                      # n 길이의 배열 탐색
            if arr[i][j:j+n] == arr[i][j+n-1:j-1:-1] or arr[i][j:j+n] == arr[i][j+n-1::-1]:
                cnt += 1                            # 회문 발견 시 cnt 1증가
            if arr2[i][j:j+n] == arr2[i][j+n-1:j-1:-1] or arr2[i][j:j+n] == arr2[i][j+n-1::-1]:
                cnt += 1
    print(f'#{tc} {cnt}')