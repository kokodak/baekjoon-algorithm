#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e18;
const int inf = 2e9;
const int SIZE = 810;
const int MOD = 1e9 + 7;

int c[SIZE][SIZE]; // 용량
int f[SIZE][SIZE]; // 유량
int cost[SIZE][SIZE]; // 비용
// 801 source
// 802 sink
vector<int> adj[SIZE];
int prevv[SIZE];
bool inQ[SIZE];
int dist[SIZE];
int resultFlow = 0;
int resultCost = 0;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    int source = 801;
    int sink = 802;
	int n, mm;
    cin >> n >> mm;
    for (int i = 1; i <= n; i++) {
        adj[source].push_back(i);
        adj[i].push_back(source);
        c[source][i] = 1;
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int work, costt;
            cin >> work >> costt;
            work += 400;
            adj[i].push_back(work);
            adj[work].push_back(i);
            c[i][work] = inf;
            cost[i][work] = costt;
            cost[work][i] = -cost[i][work];

            adj[work].push_back(sink);
            adj[sink].push_back(work);
            c[work][sink] = 1;
        }
    }
    while (1) {
        memset(inQ, 0, sizeof(inQ));
        for (int i = 0; i < SIZE; i++) {
            dist[i] = -inf;
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
                if (dist[next] >= dist[curr] + cost[curr][next]) continue;
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
            resultCost += flow * cost[prevv[i]][i];
        }
        resultFlow += flow;
    }
    cout << resultFlow << '\n' << resultCost;
	return 0;
}