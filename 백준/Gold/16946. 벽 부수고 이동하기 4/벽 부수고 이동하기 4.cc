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

int mmap[1001][1001];
bool visited[1001][1001];
int componentCnt[1000001];
int componentNode[1001][1001];
int dx[4] = {1, -1 ,0, 0};
int dy[4] = {0, 0, 1, -1};
int n, m;
int node = 0, cnt;

void dfs(int x, int y) {
	visited[x][y] = true;
	componentNode[x][y] = node;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		if (visited[nx][ny] || mmap[nx][ny] == 1) continue;
		dfs(nx, ny);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			mmap[i][j] = s[j] -'0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] || mmap[i][j] == 1) continue;
			cnt = 0;
			node++;
			dfs(i, j);
			componentCnt[node] = cnt;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mmap[i][j] == 0) continue;
			set<int> visitedSet;
			int tmp = 1;
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
				if (mmap[nx][ny] != 0 || visitedSet.count(componentNode[nx][ny])) continue;
				visitedSet.insert(componentNode[nx][ny]);
				tmp += componentCnt[componentNode[nx][ny]];
			}
			mmap[i][j] = tmp % 10;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mmap[i][j];
		}
		cout << '\n';
	}
	return 0;
}