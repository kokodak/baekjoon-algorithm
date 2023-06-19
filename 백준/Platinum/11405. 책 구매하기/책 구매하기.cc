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

int c[250][250]; // 용량
int f[250][250]; // 유량
int cost[250][250]; // 비용
// 0 ~ 99 사람
// 100 ~ 199 서점
// 200 source
// 201 sink
vector<int> adj[250];
int prevv[250];
bool inQ[250];
int dist[250];
int result = 0;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int source = 200;
    int sink = 201;
	int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> c[i][sink];
        adj[i].push_back(sink);
        adj[sink].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        cin >> c[source][i + 100];
        adj[source].push_back(i + 100);
        adj[i + 100].push_back(source);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i + 100][j];
            cost[j][i + 100] = -cost[i + 100][j];
            c[i + 100][j] = inf;
            adj[i + 100].push_back(j);
            adj[j].push_back(i + 100);
        }
    }
    while (1) {
        memset(inQ, 0, sizeof(inQ));
        for (int i = 0; i < 250; i++) {
            dist[i] = inf;
            prevv[i] = -1;
        }
        queue<int> que;
        dist[source] = 0;
        que.push(source);
        inQ[source] = true;
        while (!que.empty()) {
            int curr = que.front();
            que.pop();
            inQ[curr] = false;
            for(int next : adj[curr]) {
                if (c[curr][next] - f[curr][next] <= 0) continue;
                if (dist[next] <= dist[curr] + cost[curr][next]) continue;
                dist[next] = dist[curr] + cost[curr][next];
                prevv[next] = curr;
                if (!inQ[next]) {
                    que.push(next);
                    inQ[next] = true;
                }
            }
        }
        if (prevv[sink] == -1) break; // 증가경로 X
        int flow = inf;
        for (int i = sink; i != source; i = prevv[i]) {
            flow = min(flow, c[prevv[i]][i] - f[prevv[i]][i]);
        }
        for (int i = sink; i != source; i = prevv[i]) {
            f[prevv[i]][i] += flow;
            f[i][prevv[i]] -= flow;
            result += flow * cost[prevv[i]][i];
        }
    }
    cout << result;
	return 0;
}