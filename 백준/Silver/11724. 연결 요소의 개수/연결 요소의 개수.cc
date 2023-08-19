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

vector<int> adj[1001];
bool visited[1001];

void go(int node) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); i++) {
        int next = adj[node][i];
        if (visited[next]) continue;
        go(next);
    }
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        go(i);
        ans++;
    }
    cout << ans;
	return 0;
}