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
	
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		string ss = "";
		for (int j = 2; j < s.size(); j++) {
			ss.push_back(s[j]);
		}
		if (stoi(ss) <= 90) ans++;
	}
	cout << ans;
	return 0;
}