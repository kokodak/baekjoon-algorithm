#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

int mmap[51][51];
int ans = INF;
int n, m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> v;
bool visited[11];
bool visited1[51][51];

int bfs() {
	int tmp[51][51];
	int zcnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = mmap[i][j];
			if (tmp[i][j] == 0 || tmp[i][j] == 2) zcnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited1[i][j] = false;
		}
	}
	queue<pair<pair<int, int>, int>> que;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tmp[i][j] == -1) que.push({{i, j}, 0});
		}
	}
	int ret = -INF;
	int ccnt = 0;
	while (!que.empty()) {
		int x = que.front().first.first;
		int y = que.front().first.second;
		int t = que.front().second;
		que.pop();
		ret = max(ret, t);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= n || nx < 0 || ny >= n || ny < 0) continue;
			if (visited1[nx][ny]) continue;
			if (tmp[nx][ny] == -1 || tmp[nx][ny] == 1) continue;
			visited1[nx][ny] = true;
			tmp[nx][ny] = -1;
			que.push({{nx, ny}, t + 1});
			ccnt++;
		}
	}
	if (ccnt == zcnt) return ret;
	return -1;
}

void virus(int cnt, int idx) {
	if (m == cnt) {
		int k = bfs();
		if (k != -1) ans = min(ans, k);
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		mmap[x][y] = -1;
		virus(cnt + 1, i + 1);
		mmap[x][y] = 2;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	int zcnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mmap[i][j];
			if (mmap[i][j] == 2) v.push_back({i, j});
		}
	}
	virus(0, 0);
	if (ans == INF) cout << -1;
	else cout << ans;
	return 0;
}