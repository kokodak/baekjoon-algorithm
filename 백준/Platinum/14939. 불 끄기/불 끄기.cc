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

bool mmap[11][11];
bool tmp[11][11];
int dx[5] = {0, 0, 0, 1, -1};
int dy[5] = {0, 1, -1, 0, 0};

void copyMap() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			tmp[i][j] = mmap[i][j];
		}
	}
}

void on(int x, int y) {
	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
		tmp[nx][ny] = !tmp[nx][ny];
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for (int i = 0; i < 10; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 10; j++) {
			if (s[j] == 'O') mmap[i][j] = true;
		}
	}
	int ans = inf;
	for (int i = 0; i < 1024; i++) {
		copyMap();
		int cnt = 0;
		for (int j = 0; j < 10; j++) {
			if ((1 << j) & i) {
				// 비트가 켜져있다면
				on(0, 9 - j);
				cnt++;
			}
		}
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if (tmp[j - 1][k]) {
					on(j, k);
					cnt++;
				}
			}
		}
		bool flag = false;
		for (int j = 0; j < 10; j++) {
			if (tmp[9][j]) {
				flag = true;
				break;
			}
		}
		if (!flag) {
			// cout << cnt << endl;
			ans = min(ans, cnt);
		}
	}
	if (ans == inf) cout << -1;
	else cout << ans;
	return 0;
}