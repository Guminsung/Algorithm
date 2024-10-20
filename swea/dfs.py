"""
1
7 8
1 2 1 3 2 5 2 4 4 6 5 6 6 7 3 7
"""

                # s=1, V=7
def DFS(s, V):  # s 시작정점, V 정점개수(1번부터인 정점의 마지막 정점)
    visited = [0] * (V + 1)  # 방문한 정점을 표시 # visited=[0,1,1,1,1,1,1,1]
    stack = []  # 스택 생성                      #          0 1 2 3 4 5 6 7
    print(s, end=' ')
    visited[s] = 1  # 시작정점 방문표시
    v = s # v = 1
    while True:     # adj[3] = [4,5,7] -> w = 4
        for w in adjL[v]:  # v에 인접하고, 방문 안한 w가 있으면
            if visited[w] == 0:
                stack.append(v)  # push(v) 현재 정점을 push하고
                v = w  # w에 방문     # v = 3
                print(v, end=' ')
                visited[w] = 1  # w에 방문 표시
                break  # for w, v부터 다시 탐색
        else:  # 남은 인접정점이 없어서 break가 걸리지 않은 경우
            if len(stack) > 0:  # 이전 갈림길을 스택에서 꺼내서... if TOP > -1
                v = stack.pop() # v = 1
            else:  # 되돌아갈 곳이 없으면 or 남은 갈림길이 없으면 탐색종료
                break  # while True:


T = int(input())
for tc in range(1, T + 1):
    V, E = map(int, input().split())    # 7,8
    adjL = [[] for _ in range(V + 1)]   # 2차원 배열 / V+1 = 8
    arr = list(map(int, input().split())) # [1,2,1,3,2,4,...,]
    for i in range(E):  # E = 8              0 1 2 3 4 5
        v1, v2 = arr[i * 2], arr[i * 2 + 1] # i*2 = 0,2,4,6,8,...
        adjL[v1].append(v2) # adj[1]->[2,3] # adj[4]=[2]
        adjL[v2].append(v1) # adj[2]->[1,4,5] # adj[3]=[1]
    DFS(1, V)