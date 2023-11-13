#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

int arr[10001];
int p[10001];
bool visited[10001];

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (arr[a] < arr[b]) p[b] = a;
	else p[a] = b;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	memset(p, -1, sizeof(p));
	for (int i = 0; i < m; i++) {
		int v, w;
		cin >> v >> w;
		merge(v, w);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int root = find(i);
		if (root == -1) {
			visited[root] = true;
			ans += arr[root];
			continue;
		}
		if (visited[root]) continue;
		visited[root] = true;
		ans += arr[root];
	}
	if (ans > k) cout << "Oh no";
	else cout << ans;
	return 0;
}