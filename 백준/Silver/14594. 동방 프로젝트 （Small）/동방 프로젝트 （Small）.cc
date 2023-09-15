#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

int p[1000001];

int find(int x) {
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a > b) p[b] = a;
	else p[a] = b;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	while (m--) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < y;) {
			int root = find(i);
			if (root == i) {
				merge(i, i + 1);
				i++;
			}
			else i = root;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n;) {
		int root = find(i);
		if (root == i) {
			ans++;
			i++;
		}
		else {
			ans++;
			i = root + 1;
		}
	}
	cout << ans;
	return 0;
}