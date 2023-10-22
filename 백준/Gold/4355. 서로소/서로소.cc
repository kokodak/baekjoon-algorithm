#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while (1) {
		long long n;
		cin >> n;
		if (n == 0) break;
		long long nn = n;
		long long ans = n;
		for (long long i = 2; i * i <= n; i++) {
			if (!(n % i)) {
				ans = ans / i * (i - 1);
				while (!(n % i)) n /= i;
			}
		}
		if (n > 1) {
			ans = ans / n * (n - 1);
		}
		if (nn == 1) cout << 0 << '\n'; 
		else cout << ans << '\n';
	}
	return 0;
}