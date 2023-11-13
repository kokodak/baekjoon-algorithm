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

int p[10010];
int arr[10010];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (arr[u] < arr[v]) {
		p[u] += p[v];
		p[v] = u;
	}
	else {
		p[v] += p[u];
		p[u] = v;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(p, -1, sizeof(p));
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	int summ = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i] < 0) summ += arr[i];
	}
	if (summ > k) cout << "Oh no";
	else cout << summ;
	return 0;
}