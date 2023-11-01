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
	
	ll n, m, k;
	cin >> n >> m >> k;
	vector<pair<ll, ll>> v;
	ll maxx = -INF;
	for (int i = 0; i < k; i++) {
		ll vvv, c;
		cin >> vvv >> c;
		v.push_back({c, vvv});
		maxx = max(maxx, c);
	}
	sort(v.begin(), v.end(), less<>());
	// 최솟값을 결정한다.
	ll lo = 1;
	ll hi = maxx;
	// X 도수, Y 선호도
	bool ok = false;
	while (lo <= hi) {
		ll mid = (lo + hi) >> 1; // 도수 레벨의 최댓값
		vector<ll> vv;
		for (int i = 0; i < k; i++) {
			if (v[i].X > mid) break;
			vv.push_back(v[i].Y);
		}
		ll summ = 0;
		if (n > vv.size()) {
			summ = -1;
		}
		else {
			sort(vv.begin(), vv.end(), greater<>());
			for (int i = 0; i < n; i++) {
				summ += vv[i];
			}
		}
		if (summ < m) {
			lo = mid + 1;
		}
		else {
			// 맥주 선호도가 m 이상일때
			ok = true;
			hi = mid - 1;
		}
	}
	if (ok) cout << lo;
	else cout << -1;
	return 0;
}