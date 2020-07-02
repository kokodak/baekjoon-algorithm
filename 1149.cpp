#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#pragma warning (disable: 4996)

using namespace std;

int min(int a, int b) {
	int min;
	min = a < b ? a : b;
	return min;
}

int main(void) {
	int N;
	int dp[1001][3];
	int map[1001][3];
	int result;
	//R 0
	//G 1
	//B 2
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dp[1][0] = map[1][0];
	dp[1][1] = map[1][1];
	dp[1][2] = map[1][2];

	for (int i = 2; i <= N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + map[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + map[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + map[i][2];
	}

	result = min(min(dp[N][0], dp[N][1]), dp[N][2]);

	cout << result;
	return 0;
}
