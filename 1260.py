import sys
from collections import deque
n, m, v = map(int, sys.stdin.readline().split())
graph = {x+1: [] for x in range(n)}

def dfs(graph, start):
    
    stack = [start]
    visited = [start]
    
    while stack:
        num = stack[-1]
        visitcheck = list(set(graph[num]) - set(visited))
        visitcheck.sort()
 
        if visitcheck:
            stack.append(visitcheck[0])
            visited.append(visitcheck[0])
        else:
            #print(stack)
            stack.pop()
            
    for i in range(len(visited)):
        print(visited[i], end = " ")
    print()
        
    return None

def bfs(graph, start):
    
    queue = deque([start])
    visited = [start]
    
    while queue:
        num = queue[0]
        visitcheck = list(set(graph[num]) - set(visited))
        visitcheck.sort()

        if visitcheck:
            for i in range(len(visitcheck)):
                queue.append(visitcheck[i])
                visited.append(visitcheck[i])
            queue.popleft()
        else:
            queue.popleft()
            
    for i in range(len(visited)):
        print(visited[i], end = " ")
    print()
        
    return None

if __name__ == "__main__":
    for _ in range(m):
        a, b = map(int, sys.stdin.readline().split())
        graph[a].append(b)
        graph[b].append(a)

    for i in range(1, n+1):
        graph[i].sort()

    dfs(graph, v)
    bfs(graph, v)
