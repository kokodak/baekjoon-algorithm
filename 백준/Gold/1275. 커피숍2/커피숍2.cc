#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

long long seg[1 << 18];

void update(int node, int nl, int nr, int idx, long long k) {
	if (nl > idx || nr < idx) return;
	if (nl == nr) {
		seg[node] = k;
		return;
	}
	int mid = (nl + nr) >> 1;
	update(node * 2, nl, mid, idx, k);
	update(node * 2 + 1, mid + 1, nr, idx, k);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

long long query(int node, int s, int e, int nl, int nr) {
	if (s > nr || e < nl) return 0;
	if (s <= nl && nr <= e) return seg[node];
	int mid = (nl + nr) >> 1;
	return query(node * 2, s, e, nl, mid) + query(node * 2 + 1, s, e, mid + 1, nr);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		update(1, 1, n, i, k);
	}
	while (q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y) swap(x, y);
		cout << query(1, x, y, 1, n) << '\n';
		update(1, 1, n, a, b);
	}
	return 0;
}