import sys
str1 = sys.stdin.readline().strip()
str2 = sys.stdin.readline().strip()
str1_len = len(str1)
str2_len = len(str2)
DP = [[0] * (str2_len + 1) for _ in range(str1_len + 1)]

for i in range(str1_len):
    for j in range(str2_len):
        if str1[i] == str2[j]:
            DP[i + 1][j + 1] = DP[i][j] + 1
        else:
            DP[i + 1][j + 1] = max(DP[i][j + 1], DP[i + 1][j])
print(DP[-1][-1])
