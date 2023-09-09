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

int arr[100001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	ll lo = -1;
	for (int i = 0; i < n; i++) lo = max(lo, (ll)arr[i]);
	ll hi = 1e11;
	ll mid;
	while (lo <= hi) {
		mid = (lo + hi) >> 1;
		ll cnt = 1;
		ll summ = 0;
		for (int i = 0; i < n; i++) {
			if (summ + arr[i] > mid) {
				cnt++;
				summ = arr[i];
			}
			else summ += arr[i];
		}
		if (cnt > m) lo = mid + 1;
		else hi = mid - 1;
	}
	cout << lo;
	return 0;
}