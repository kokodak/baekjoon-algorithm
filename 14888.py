N = int(input())
num = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())

min_ = 1000000000
max_ = -1000000000

def dfs(i, res, add, sub, mul, div):
    global max_, min_
    if i == N:
        max_ = max(res, max_)
        min_ = min(res, min_)

    else:
        if add:
            dfs(i+1, res+num[i], add-1, sub, mul, div)
        if sub:
            dfs(i+1, res-num[i], add, sub-1, mul, div)
        if mul:
            dfs(i+1, res*num[i], add, sub, mul-1, div)
        if div:
            dfs(i+1, int(res/num[i]), add, sub, mul, div-1)
dfs(1, num[0], add, sub, mul, div)
print(max_)
print(min_)
