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

ll dp[1000001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    ll summ = 0;
    for (int i = 3; i <= n; i++) {
        dp[i] = ((dp[i - 1] * 2) % MOD + (dp[i - 2] * 3) % MOD) % MOD;
        summ += dp[i - 3];
        summ %= MOD;
        dp[i] += (summ * 2) % MOD;
        dp[i] %= MOD;
    }
    cout << dp[n];
	return 0;
}