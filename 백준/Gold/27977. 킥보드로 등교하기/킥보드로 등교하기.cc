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

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int l, n, k;
	cin >> l >> n >> k;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}
	int lo = 0;
	int hi = 2e5 + 1;
	int mid;
	int ans = l;
	while (lo <= hi) {
		mid = (lo + hi) >> 1; // 배터리
		int location = 0;
		bool flag = false;
		for (int i = 0; i < k; i++) {
			auto it = lower_bound(v.begin(), v.end(), mid + location);
			if (mid + location != *it) it--;
			if (it < v.begin()) break;
			location = *it;
			if (mid + location >= l) {
				flag = true;
				break;
			}
		}
		if (flag) {
			hi = mid - 1;
			ans = min(ans, mid);
		}
		else {
			lo = mid + 1;
		}
	}
	cout << ans;
	return 0;
}