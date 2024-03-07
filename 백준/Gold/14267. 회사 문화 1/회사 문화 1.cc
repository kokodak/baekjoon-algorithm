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

ll seg[SIZE];
ll lazy[SIZE];
vector<int> v[100001];
bool visited[100001];
int s[100001];
int e[100001];
int cnt = -1;

// ETT
void go(int node) {
	visited[node] = true;
	s[node] = ++cnt;
	for (int next : v[node]) {
		if (visited[next]) continue;
		go(next);
	}
	e[node] = cnt;
}

void update_lazy(int node, int nodeLeft, int nodeRight) {
	if (lazy[node] != 0) {
        // 만약 해당 세그먼트 트리 노드에 lazy 값이 있다면
		if (nodeLeft != nodeRight) {
			// 만약 리프노드가 아니라면 lazy 값을 자식노드에게 전파
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		seg[node] += lazy[node] * (nodeRight - nodeLeft + 1);
		lazy[node] = 0; // 자식에게 전파 후, 자신 lazy 값은 삭제
	}
    else return;
}

void update_range(int node, int start, int end, int nodeLeft, int nodeRight, ll k) {
	update_lazy(node, nodeLeft, nodeRight); // 항상 먼저 lazy 갱신 
	if (nodeLeft > end || nodeRight < start) return;
	if (start <= nodeLeft && nodeRight <= end) {
		lazy[node] += k;
		update_lazy(node, nodeLeft, nodeRight);
		return;
	}
	int mid = (nodeLeft + nodeRight) >> 1;
	update_range(node * 2, start, end, nodeLeft, mid, k);
	update_range(node * 2 + 1, start, end, mid + 1, nodeRight, k);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll sum_range(int node, int start, int end, int nodeLeft, int nodeRight) {
	update_lazy(node, nodeLeft, nodeRight); // 항상 먼저 lazy 갱신 
	if (nodeLeft > end || nodeRight < start) return 0;
	if (start <= nodeLeft && nodeRight <= end) return seg[node];
	int mid = (nodeLeft + nodeRight) >> 1;
	return sum_range(node * 2, start, end, nodeLeft, mid) + sum_range(node * 2 + 1, start, end, mid + 1, nodeRight);
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		if (k == -1) continue;
		k--;
		v[k].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		go(i);
	}
	while (m--) {
		int i, w;
		cin >> i >> w;
		i--;
		update_range(1, s[i], e[i], 0, n - 1, w);
	}
	for (int i = 0; i < n; i++) {
		cout << sum_range(1, s[i], s[i], 0, n - 1) << " ";
	}
	return 0;
}