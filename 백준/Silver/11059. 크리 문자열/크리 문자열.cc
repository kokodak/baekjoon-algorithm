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

int pfx[1001];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		pfx[i] = pfx[i - 1] + s[i - 1] - '0';
	}
	int ans = -inf;
	for (int i = 0; i < s.size(); i++) {
		for (int j = i + 1; j < s.size(); j += 2) {
			// [i, j]
			if (pfx[(i + j + 2) / 2] - pfx[i] == pfx[j + 1] - pfx[(i + j + 2) / 2]) {
				ans = max(ans, j - i + 1);
			}
		}
	}
	cout << ans;
	return 0;
}