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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1}; // ^ < v >
int mmapp[8][8];
int n, m;
vector<pii> cctv;
vector<int> dirCase;
int anss = inf;

void dfs(int mmap[8][8], int x, int y, int dir) { // dir 방향으로 한 줄만 체크
	if (dir > 3) dir %= 4;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx < 0 || nx >= n || ny < 0 || ny >= m) return;
	if (mmap[nx][ny] == 6) return;
	if (mmap[nx][ny] >= 1 && mmap[nx][ny] <= 5) dfs(mmap, nx, ny, dir);
	else {
		mmap[nx][ny] = 9;
		dfs(mmap, nx, ny, dir);
	}
}

int findAns(int cctvSize) {
	int mmap[8][8];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			mmap[i][j] = mmapp[i][j];
		}
	}
	for (int i = 0; i < cctvSize; i++) {
		int cctvNumber = mmapp[cctv[i].X][cctv[i].Y];
		if (cctvNumber == 1) {
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i]);
		}
		else if (cctvNumber == 2) {
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i]);
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i] + 2);
		}
		else if (cctvNumber == 3) {
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i]);
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i] + 1);
		}
		else if (cctvNumber == 4) {
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i]);
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i] + 1);
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i] + 2);
		}
		else if (cctvNumber == 5) {
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i]);
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i] + 1);
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i] + 2);
			dfs(mmap, cctv[i].X, cctv[i].Y, dirCase[i] + 3);
		}
	}
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << mmap[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mmap[i][j] == 0) ans++;
		}
	}
	return ans;
}

void go(int depth, int cctvSize) {
	if (depth == cctvSize) {
		anss = min(anss, findAns(cctvSize));
		return;
	}
	for (int i = 0; i < 4; i++) {
		dirCase.push_back(i);
		go(depth + 1, cctvSize);
		dirCase.pop_back();
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mmapp[i][j];
			if (mmapp[i][j] >= 1 && mmapp[i][j] <= 5) {
				cctv.push_back({i, j});
			}
		}
	}
	go(0, cctv.size());
	cout << anss;
	return 0;
}