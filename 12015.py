import sys
num = int(input())
arr = list(map(int, sys.stdin.readline().split()))
LIS = [arr[0]]

def search(i, f, k):#이진탐색 알고리즘 // 리턴값은 리스트의 인덱싱값

    if i == f :
        return i
    
    m = int((i + f) / 2)
    
    if LIS[m] == k :
        return m

    elif LIS[m] < k :
        return search(m + 1, f, k)
    
    else :
        return search(i, m, k)
    
for i in range(1, len(arr)) :
    if num == 1 :
        print(1)
        break
    
    if arr[i] > LIS[-1] :
        LIS.append(arr[i])

    else :
        LIS[search(0, len(LIS) - 1, arr[i])] = arr[i]
        
print(len(LIS))
