import sys
N = int(sys.stdin.readline())
k = N // 10
d = N % 10
arr = [0] * 10

if N <= 9 :
    for i in range(1, N + 1):
        arr[i] += 1
else:
    for i in range(1, k + 1):
        if i == k:
            while i != 0:
                x = i % 10
                arr[x] += d + 1
                i //= 10
        else:
            while i != 0:
                x = i % 10
                arr[x] += 10
                i //= 10
                
    for i in range(1, 10):
        arr[i] += 1
        
    for i in range(10):
        arr[i] += k - 1

    for i in range(d + 1):
        arr[i] += 1
        
for i in range(10):
    print(arr[i], end = " ")
