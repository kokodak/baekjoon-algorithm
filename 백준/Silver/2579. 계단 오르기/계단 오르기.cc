#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
const int INF = 999999999;
const int MOD = 10007;
using namespace std;
/*
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

long long dp[301];
int stairs[301];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int result = -INF;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
	}
	dp[0] = 0;
	dp[1] = stairs[1];
	dp[2] = dp[1] + stairs[2];
	dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(stairs[i - 1] + dp[i - 3] + stairs[i], dp[i - 2] + stairs[i]);
	}

	cout << dp[n];
	return 0;
}