#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int INF = 2e9;
const int inf = 1e9;
const int SIZE = 1 << 18;
const int MOD = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct A {
	int node;
	int oilCost;
	ll cost;
};

struct compare {
	bool operator()(A& a, A& b) {
		return a.cost > b.cost;
	}
};

vector<pii> adj[2501];
ll dist[2501][2501]; // j의 기름 비용으로 i에 도착했을 때의 최소 비용합 
int oil[2501];

void dijkstra(int start) {
	for (int i = 0; i < 2501; i++) {
		for (int j = 0; j < 2501; j++) {
			dist[i][j] = 2e10;
		}
	}
	priority_queue<A, vector<A>, compare> pq;
	dist[start][oil[start]] = 0;
	pq.push({start, oil[start], 0});
	while (!pq.empty()) {
		int node = pq.top().node;
		int oilCost = pq.top().oilCost;
		ll cost = pq.top().cost;
		pq.pop();
		if (dist[node][oilCost] < cost) continue;
		for (pii next : adj[node]) {
			int nextNode = next.X;
			ll nextCost = (ll)next.Y * oilCost + cost;
			if (nextCost >= dist[nextNode][oilCost]) continue;
			dist[nextNode][oilCost] = nextCost;
			pq.push({nextNode, min(oilCost, oil[nextNode]), nextCost});
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> oil[i];
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dijkstra(1);
	ll ans = 2e10;
	//for (int i = 1; i < 30; i++) cout << dist[n][i] << endl;
	for (int i = 1; i < 2501; i++) ans = min(ans, dist[n][i]);
	cout << ans;
	return 0;
}