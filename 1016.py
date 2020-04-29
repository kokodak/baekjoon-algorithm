import sys
judge = [0 for i in range(0, 1000002)]#구간 사이 모든 칸
count = 0
min_, max_ = map(int, sys.stdin.readline().split(' '))
for i in range(2, 1000000) :#구간 사이 모든 제곱수의 배수 제외
    
    if min_ % i**2 != 0 :
        min_div = (min_ // i**2) + 1
        
    elif min_ % i**2 == 0 :
        min_div = min_ // i**2
        
    max_div = max_ // i**2
    
    for j in range(min_div, max_div + 1) :
        judge[(i**2) * j - min_] = 1
        
sqr_min = int(round(min_ ** 0.5))
sqr_max = int(max_ ** 0.5)

for i in range(sqr_min, sqr_max + 1) :#구간 사이 모든 제곱수 제외
    
    if i**2 >= min_ and i**2 <= max_ and i != 1 :
        judge[(i**2) - min_] = 1
        
for i in range(0, 1000002) :
    
    if judge[i] == 1 :
        count += 1
        
length = max_ - min_ + 1
print(length - count)
