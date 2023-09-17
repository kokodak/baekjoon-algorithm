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

vector<int> adj[101001];
bool visited[1001001];

int bfs(int n) {
	queue<pii> que;
	que.push({1, 1});
	visited[1] = true;
	while (!que.empty()) {
		int node = que.front().X;
		int dist = que.front().Y;
		if (node == n) return dist;
		que.pop();
		for (int next : adj[node]) {
			if (visited[next]) continue;
			visited[next] = true;
			if (next > n) que.push({next, dist});
			else que.push({next, dist + 1});
		}
	}
	return -1;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			int a;
			cin >> a;
			adj[a].push_back(n + i + 1);
			adj[n + i + 1].push_back(a);
		}
	}
	cout << bfs(n);
	return 0;
}