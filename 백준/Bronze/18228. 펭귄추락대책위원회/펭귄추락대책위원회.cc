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

int arr[200001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int idx;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == -1) {
			idx = i;
		}
	}
	int ans = 0;
	int minn = inf;
	for (int i = 0; i < idx; i++) {
		minn = min(minn, arr[i]);
	}
	if (minn != inf) ans += minn;
	minn = inf;
	for (int i = idx + 1; i < n; i++) {
		minn = min(minn, arr[i]);
	}
	if (minn != inf) ans += minn;
	cout << ans;
	return 0;
}