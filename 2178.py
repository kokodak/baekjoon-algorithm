from collections import deque
n, m = map(int, input().split())
miro = [list(map(int, input().strip())) for _ in range(n)]
dist = [[0 for _ in range(m)] for _ in range(n)]
visit = [[False for _ in range(m)] for _ in range(n)]
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
#(dx[i], dy[i])는 순서대로 오른쪽, 왼쪽, 아래, 위

#BFS start
que = deque()
que.append((0, 0))
visit[0][0] = True
dist[0][0] = 1

while que :
    ax, ay = que.popleft()
    for i in range(4) :
        new_x = ax + dx[i]
        new_y = ay + dy[i]

        if 0 <= new_x < n and 0 <= new_y < m :
            if visit[new_x][new_y] == False and miro[new_x][new_y] == 1 :
                que.append((new_x, new_y))
                dist[new_x][new_y] = dist[ax][ay] + 1
                visit[new_x][new_y] = True

result = dist[n - 1][m - 1]
print(result)
