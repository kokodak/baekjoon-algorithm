import sys
N, K = map(int, sys.stdin.readline().split())

dp = [[0 for i in range(K + 1)] for x in range(N) ]
W = [0 for x in range(N)]
V = [0 for x in range(N)]

for i in range(N) :
    W[i], V[i] = map(int, sys.stdin.readline().split())

for j in range(W[0], K + 1) : #자신의 무게 이상부터 자신의 가치 대입
    dp[0][j] = V[0]
    
for i in range(1, N) :

    for j in range(K + 1) :
        if W[i] > j :
            dp[i][j] = dp[i - 1][j]
        else :    
            dp[i][j] = max(V[i] + dp[i - 1][j - W[i]], dp[i - 1][j])
            
print(dp[-1][-1])
