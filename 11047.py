N, K = map(int, input().split())
coin = []
idx = N - 1
result = 0

for i in range(N):
    num = int(input())
    coin.append(num)

while K != 0:
    if coin[idx] > K:
        idx -= 1
        continue
    result += K // coin[idx]
    K -= (K // coin[idx]) * coin[idx]

print(result)
