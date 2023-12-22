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

ll price[100001];
ll dist[100001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) cin >> dist[i];
	for (int i = 0; i < n; i++) cin >> price[i];
	int now = 0;
	ll cnt = dist[0];
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		if (price[now] > price[i]) {
			ans += cnt * price[now];
			now = i;
			if (i != n - 1) cnt = dist[i];
		}
		else {
			if (i == n - 1) ans += cnt * price[now];
			else cnt += dist[i];
		}
	}
	cout << ans;
	return 0;
}