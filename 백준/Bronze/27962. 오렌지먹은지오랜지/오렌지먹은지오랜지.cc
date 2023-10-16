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
	string s;
	cin >> s;
	int ssize = s.size();
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 0; j < i; j++) {
			if (cnt == 2) {
				break;
			}
			if (s[j] != s[ssize - i + j]) {
				cnt++;
			}
		}
		if (cnt == 1) {
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}