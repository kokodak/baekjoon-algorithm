#include <bits/stdc++.h> 
using namespace std;

const int INF = 987654321;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

int n;
int mmap[101][101];
bool vi[101][101];
int dx[4] = {1, -1 ,0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y, int h) {
	vi[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (!vi[nx][ny] && mmap[nx][ny] > h) {
				dfs(nx, ny, h);
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mmap[i][j];
		}
	}
	int ans = -INF;
	for (int k = 1; k <= 100; k++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vi[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!vi[i][j] && mmap[i][j] > k) {
					dfs(i, j, k);
					cnt++;
				}
			}
		}
		ans = max(ans, cnt);
	}
	if (ans == 0) cout << 1;
	else cout << ans;
	return 0;
}