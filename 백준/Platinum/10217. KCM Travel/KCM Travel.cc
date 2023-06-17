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
	int cost;
	int time;
};

vector<A> adj[101];
int dist[101][10001]; // 1번 공항에서 i번 공항을 j의 비용으로 도착했을 때의 최소 소요 시간

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int t, n, m, k;
    cin >> t >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        adj[u].push_back({v, c, d});
    }
    for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dist[i][j] = INF;
		}
	}
	dist[1][0] = 0;
    for (int cost = 0; cost <= m; cost++) {
        for (int node = 1; node <= n; node++) {
            if (dist[node][cost] == INF) continue;
            for (A next : adj[node]) {
                int nextNode = next.node;
                int nextCost = next.cost + cost;
                int nextTime = next.time + dist[node][cost];
                if (nextCost > m) continue;
                dist[nextNode][nextCost] = min(dist[nextNode][nextCost], nextTime); 
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= m; i++) {
        ans = min(ans, dist[n][i]);
    }
    if (ans == INF) cout << "Poor KCM";
    else cout << ans;
	return 0;
}
