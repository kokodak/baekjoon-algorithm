#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int INF = 2e9;
const int inf = 1e9;
const int SIZE = 1 << 18;
const int MOD = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll dp[81];

ll fibo(int n) {
	ll& ret = dp[n];
	if (ret != -1) return ret;
	if (n == 0) return ret = 0;
	if (n == 1 || n == 2) return ret = 1;
	return ret = fibo(n - 1) + fibo(n - 2);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dp, -1, sizeof(dp));
	int n;
	cin >> n;
	cout << fibo(n) * 4 + fibo(n - 1) * 2;
	return 0;
}