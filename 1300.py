N = int(input())
K = int(input())

left = 1
right = K
ans = 0

while left <= right :
    summ = 0
    mid = (left + right)//2
    
    for i in range(1, N+1) :
        
        summ += min(mid//i, N)

    if summ >= K :
        ans = mid
        right = mid - 1
    
    elif summ < K :

        left = mid + 1

print(ans)
