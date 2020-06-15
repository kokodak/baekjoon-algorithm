from collections import deque

N, M = map(int, input().split())
arr = [list(map(int, input().strip())) for _ in range(N)]
visit = [[[False] * 2 for _ in range(M)] for _ in range(N)]
dist = [[[-1] * 2 for _ in range(M)] for _ in range(N)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

#BFS start point
que = deque()
que.append((0,0,0))
visit[0][0][0] = True
dist[0][0][0] = 1

while que:
    x, y, z = que.popleft()
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if 0 <= nx < N and 0 <= ny < M:
            if visit[nx][ny][z] == False:
                if arr[nx][ny] == 0:
                    que.append((nx,ny,z))
                    visit[nx][ny][z] = True
                    dist[nx][ny][z] = dist[x][y][z] + 1

                elif arr[nx][ny] == 1:
                    if z == 0:
                        que.append((nx,ny,1))
                        visit[nx][ny][1] = True
                        dist[nx][ny][1] = dist[x][y][z] + 1
                        
if dist[N - 1][M - 1][0] == -1 and dist[N - 1][M - 1][1] == -1:
    print(-1)

elif dist[N - 1][M - 1][0] == -1 and dist[N - 1][M - 1][1] != -1:
    print(dist[N - 1][M - 1][1])

elif dist[N - 1][M - 1][0] != -1 and dist[N - 1][M - 1][1] == -1:
    print(dist[N - 1][M - 1][0])
else:
    print(min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]))
