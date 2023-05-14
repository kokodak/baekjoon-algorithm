#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

bool visited[100001];
int p[100001];
vector<int> ans;

struct info {
	int x;
	int time;
};

int bfs(int n, int k) {
	queue<info> que;
	que.push({n, 0});
	int idx = k;
	visited[n] = true;
	while (!que.empty()) {
		int x = que.front().x;
		int time = que.front().time;
		que.pop();
		if (x == k) {
			while (1) {
				if (idx == n) break;
				idx = p[idx];
				ans.push_back(idx);
			}
			return time;
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			visited[x - 1] = true;
			que.push({x - 1, time + 1});
			p[x - 1] = x;
		}
		if (x + 1 < 100001 && !visited[x + 1]) {
			visited[x + 1] = true;
			que.push({x + 1, time + 1});
			p[x + 1] = x;
		}
		if (2 * x < 100001 && !visited[2 * x]) {
			visited[2 * x] = true;
			que.push({2 * x, time + 1});
			p[2 * x] = x;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	ans.push_back(k);
	cout << bfs(n, k) << endl;
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}