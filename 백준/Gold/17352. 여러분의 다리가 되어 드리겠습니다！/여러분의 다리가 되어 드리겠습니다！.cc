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

int p[300001];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	p[b] = a;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(p, -1, sizeof(p));
	int n;
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	int ans1, ans2;
	int prev = find(1);
	for (int i = 1; i <= n; i++) find(i);
	for (int i = 2; i <= n; i++) {
		if (prev != find(i)) {
			ans1 = i - 1;
			ans2 = i;
			break;
		}
		prev = find(i);
	}
	cout << ans1 << " " << ans2;
	return 0;
}