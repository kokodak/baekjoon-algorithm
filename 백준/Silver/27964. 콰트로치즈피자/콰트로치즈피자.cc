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
	vector<string> v;
	set<string> sset;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int ssize = s.size();
		if (ssize < 6) continue;
		if (s.substr(ssize - 6, ssize) == "Cheese") {
			sset.insert(s);
		}
	}
	if (sset.size() >= 4) cout << "yummy";
	else cout << "sad";
	return 0;
}