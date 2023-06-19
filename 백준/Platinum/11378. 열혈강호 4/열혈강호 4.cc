#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
const int inf = 2e9;
const int SIZE = 2010;
const int MOD = 1e9 + 7;

int c[SIZE][SIZE]; // 용량
int f[SIZE][SIZE]; // 유량
int cost[SIZE][SIZE]; // 비용
// 2005 source
// 2006 sink
vector<int> adj[SIZE];
int prevv[SIZE];
bool inQ[SIZE];
int dist[SIZE];
int resultFlow = 0;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int source = 2005;
    int sink = 2006;
    int source2 = 2007;
	int n, mm, k;
    cin >> n >> mm >> k;
    adj[source].push_back(source2); // 역방향 연결 해줘야 할까?
    adj[source2].push_back(source);
    for (int i = 1; i <= n; i++) {
        adj[source].push_back(i);
        adj[i].push_back(source);
        adj[source2].push_back(i);
        adj[i].push_back(source2);
        c[source][i] = 1;
        c[source][source2] = k;
        c[source2][i] = k;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int work;
            cin >> work;
            work += 1000;
            adj[i].push_back(work);
            adj[work].push_back(i);
            c[i][work] = inf;

            adj[work].push_back(sink);
            adj[sink].push_back(work);
            c[work][sink] = 1;
        }
    }
    while (1) {
        // cout << 11 << endl;
        memset(inQ, 0, sizeof(inQ));
        for (int i = 0; i < SIZE; i++) {
            dist[i] = inf;
            prevv[i] = -1;
        }
        queue<int> que;
        dist[source] = 0;
        que.push(source);
        inQ[source] = true;
        while (!que.empty()) {
            // cout << 22 << endl;
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
        }
        resultFlow += flow;
    }
    cout << resultFlow;
	return 0;
}