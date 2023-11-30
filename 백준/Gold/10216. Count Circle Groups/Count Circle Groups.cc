#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int INF = 2e9;
const int inf = 1e9;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct A {
	int x;
	int y;
	int r;
};

int p[3001];

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
	
	int t;
	cin >> t;
	while (t--) {
		vector<A> v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			p[i] = -1;
		}
		for (int i = 0; i < n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			v.push_back({x, y, r});
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int left = (v[i].x - v[j].x) * (v[i].x - v[j].x) + (v[i].y - v[j].y) * (v[i].y - v[j].y);
				int right = (v[i].r + v[j].r) * (v[i].r + v[j].r);
				if (left <= right) {
					merge(i, j);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (p[i] >= 0) continue;
			ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}