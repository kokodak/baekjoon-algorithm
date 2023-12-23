#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;
const int MOD = 1e9 + 7;

long long fac[4000001];

long long fast_pow(long long a, long long b) {
	long long ret = 1;
	while (b) {
		if (b % 2) ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, r;
	cin >> n >> r;
	
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= n; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
	}
	long long A = fac[n];
	long long B = (fac[r] * fac[n - r]) % MOD;
	long long ans = ((A % MOD) * (fast_pow(B, MOD - 2) % MOD)) % MOD;
	cout << ans;
	return 0;
}