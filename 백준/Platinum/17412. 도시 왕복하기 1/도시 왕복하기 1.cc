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

int c[405][405];
int f[405][405];
int prevv[405];
vector<int> adj[405];

int maximumFlow(int S, int E) {
	int total = 0;
	int source = S;
	int sink = E;
	while (1) {
		for (int i = 0; i < 405; i++) prevv[i] = -1;
		queue<int> que;
		que.push(source);
		while (!que.empty() && prevv[sink] == -1) {
			int node = que.front();
			que.pop();
			if (node == sink) break;
			for (int next : adj[node]) {
				if (c[node][next] == f[node][next] || prevv[next] != -1) continue;
				que.push(next);
				prevv[next] = node; 
			}
		}
		if (prevv[sink] == -1) break; // 싱크로 향하는 증가 경로가 더 이상 없다면 while문 탈출
		int flow = inf;
		for (int i = sink; i != source; i = prevv[i]) flow = min(flow, c[prevv[i]][i] - f[prevv[i]][i]);
		for (int i = sink; i != source; i = prevv[i]) {
			f[prevv[i]][i] += flow;
			f[i][prevv[i]] -= flow;
		}
		total += flow;
	}
	return total;
}


int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b] = 1;
	}
	cout << maximumFlow(1, 2);
	return 0;
}