#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
const int inf = 2e9;
const int SIZE = 1 << 18;
const int MOD = 1e9 + 7;

int dp[1000001]; // dp[i] = i를 1로 만들기 위한 연산의 최솟값

// dp[1] = 0;
// dp[2] = 1;
// dp[3] = 1;
// dp[4] = min(dp[2] + 1, dp[3] + 1) = 2;
// dp[5] = 3 = dp[4] + 1
// dp[6] = dp[2] + 1 or dp[3] + 1 or dp[5] + 1

int go(int x) { // x를 1로 만들기 위한 연산의 최솟값
	int& ret = dp[x];
	if (ret != -1) return ret;
	if (x == 0) return ret = 0;
	if (x == 1) return ret = 0;
	ret = inf;
	if (x % 3 == 0) ret = min(ret, go(x / 3) + 1);
	if (x % 2 == 0) ret = min(ret, go(x / 2) + 1);
	ret = min(ret, go(x - 1) + 1);
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int x;
	cin >> x;
	for (int i = 0; i < 1000001; i++) dp[i] = inf;
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 2; i <= x; i++) {
		if (i % 3 == 0) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
		if (i % 2 == 0) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[x];
	return 0;
}