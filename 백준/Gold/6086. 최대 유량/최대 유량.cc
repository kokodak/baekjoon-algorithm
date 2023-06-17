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

struct Edge {
    int to, c, f;
    Edge* dual;

    Edge(): Edge(-1, 0) {}

    Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}

    int spare() {
        return c - f; // 남은 용량
    }

    void addFlow(int f1) {
        f += f1;
        dual->f -= f1; // 역방향 간선에 flow 빼주기
    }
};

int ctoi(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

vector<Edge*> adj[52];
int prevv[52];
Edge* prevEdge[52];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char u, v;
        int c;
        cin >> u >> v >> c;
        int uu = ctoi(u), vv = ctoi(v);
        Edge* e1 = new Edge(vv, c);
        Edge* e2 = new Edge(uu, c); // 양방향 그래프일때, 역방향 간선의 용량은 c로 동일하다.
        // Edge* e2 = new Edge(u, 0); // 단방향 그래프일때, 역방향 간선의 용량은 0이다.
        e1->dual = e2;
        e2->dual = e1;
        adj[uu].push_back(e1);
        adj[vv].push_back(e2);
    }
    int maxFlow = 0;
    int source = ctoi('A');
    int sink = ctoi('Z');
    while (1) {
        for (int i = 0; i < 52; i++) prevv[i] = -1;
        for (int i = 0; i < 52; i++) prevEdge[i] = nullptr;
        queue<int> que;
        que.push(source);
        // BFS로 source -> sink 최단 증가 경로 찾기
        while (!que.empty() && prevv[sink] == -1) {
            int node = que.front();
            que.pop();
            for (Edge* e : adj[node]) {
                int next = e->to;
                if (e->spare() > 0 && prevv[next] == -1) {
                    // 간선의 용량이 남아있으면서, 방문되지 않은 정점이어야 함
                    que.push(next);
                    prevv[next] = node;
                    prevEdge[next] = e;
                    if (next == sink) break;
                }
            }
        }
        if (prevv[sink] == -1) break; // sink로 향하는 증가 경로가 존재하지 않는다면 종료
        int flow = inf;
        for (int i = sink; i != source; i = prevv[i]) {
            flow = min(flow, prevEdge[i]->spare());
        }
        for (int i = sink; i != source; i = prevv[i]) {
            prevEdge[i]->addFlow(flow);
        }
        maxFlow += flow;
    }
    cout << maxFlow;
	return 0;
}