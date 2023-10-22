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

// __|
// |__
// ^^|
// |^^
int dx[4][2] = {{-1, 0}, {-1, 0}, {0, 1}, {0, 1}};
int dy[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

int arr[4][4];
int n;
bool ok = false;

void go(int cnt) {
	if (ok) return;
	bool check = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == -2) {
				check = false;
				break;
			}
		}
		if (!check) break;
	}
	if (check) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
		ok = true;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == -2) {
				for (int ii = 0; ii < 4; ii++) {
					bool flag = true;
					for (int jj = 0; jj < 2; jj++) {
						int nx = i + dx[ii][jj];
						int ny = j + dy[ii][jj];
						if (nx >= n || nx < 0 || ny >= n || ny < 0) {
							flag = false;
							break;
						}
						if (arr[nx][ny] != -2) {
							flag = false;
							break;
						}
					}
					if (flag) {
						arr[i][j] = cnt;
						for (int jj = 0; jj < 2; jj++) {
							int nx = i + dx[ii][jj];
							int ny = j + dy[ii][jj];
							arr[nx][ny] = cnt;
						}
						go(cnt + 1);
						for (int jj = 0; jj < 2; jj++) {
							int nx = i + dx[ii][jj];
							int ny = j + dy[ii][jj];
							arr[nx][ny] = -2;
						}
						arr[i][j] = -2;
					}
				}
			}
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a == 1) n = 2;
	else n = 4;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = -2;
		}
	}
	b--;
	c--;
	arr[n - 1 - c][b] = -1;
	go(1);
	return 0;
}