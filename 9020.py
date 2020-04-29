n = 10000
sieve = [True] * n
m = int(n ** 0.5)
for i in range(2, m + 1):
    if sieve[i] == True:            
        for j in range(i+i, n, i):
            sieve[j] = False
arr = [i for i in range(2, n) if sieve[i] == True]

num = int(input())
for x in range(num) :
    
    a = int(input())
    aa = 0
    for z in range(0, 1228):
        if a <= arr[z] :
            break
        else :
            aa += 1
    k = float("inf")
    sol = [0, 0]
    for i in range(aa) :
        if sieve[a - arr[i]] == True :
            P = max(arr[i], a - arr[i])#7
            p = min(arr[i], a - arr[i])#3
            m = P - p
            if m < k :
                k = m
                sol[0] = p
                sol[1] = P

    print("%d %d" %(sol[0], sol[1]))
