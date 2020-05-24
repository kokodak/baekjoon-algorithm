import sys
N = int(sys.stdin.readline())
k = []

while N != 0 :
    tmp = N % 10
    k.append(tmp)
    N //= 10
    
k.sort(reverse = True)

for i in range(len(k)):
    print(k[i], end="")
