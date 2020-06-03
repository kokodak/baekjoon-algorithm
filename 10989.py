import sys
N = int(sys.stdin.readline())
sort_list = [0] * 10001
while N != 0 :
    K = int(sys.stdin.readline())
    sort_list[K] += 1
    N -= 1
for i in range(1, 10001) :
    if sort_list[i] != 0 :
        for j in range(sort_list[i]) :
            print(i)
