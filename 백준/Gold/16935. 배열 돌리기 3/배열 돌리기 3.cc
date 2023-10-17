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

int arr[101][101];
int n, m, r;

void func1() {
	int tmp[101][101];
	for (int i = 0, ii = n - 1; i < n; i++, ii--) {
		for (int j = 0; j < m; j++) {
			tmp[i][j] = arr[ii][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
}

void func2() {
	int tmp[101][101];
	for (int i = 0; i < n; i++) {
		for (int j = 0, jj = m - 1; j < m; j++, jj--) {
			tmp[i][j] = arr[i][jj];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
}

void func3() {
	int tmp[101][101];
	for (int i = 0; i < m; i++) {
		for (int j = 0, jj = n - 1; j < n; j++, jj--) {
			tmp[i][j] = arr[jj][i];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
	swap(n, m);
}

void func4() {
	int tmp[101][101];
	for (int i = 0, ii = m - 1; i < m; i++, ii--) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = arr[j][ii];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
	swap(n, m);
}

void func5() {
	int tmp[101][101];
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0, jj = m / 2; j < m / 2; j++, jj++) {
			tmp[i][jj] = arr[i][j];
		}
	}
	for (int i = 0, ii = n / 2; i < n / 2; i++, ii++) {
		for (int j = m / 2; j < m; j++) {
			tmp[ii][j] = arr[i][j];
		}
	}
	for (int i = n / 2; i < n; i++) {
		for (int j = m / 2, jj = 0; j < m; j++, jj++) {
			tmp[i][jj] = arr[i][j];
		}
	}
	for (int i = n / 2, ii = 0; i < n; i++, ii++) {
		for (int j = 0; j < m / 2; j++) {
			tmp[ii][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
}

void func6() {
	int tmp[101][101];
	for (int i = 0, ii = n / 2; i < n / 2; i++, ii++) {
		for (int j = 0; j < m / 2; j++) {
			tmp[ii][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n / 2; i++) {
		for (int j = m / 2, jj = 0; j < m; j++, jj++) {
			tmp[i][jj] = arr[i][j];
		}
	}
	for (int i = n / 2, ii = 0; i < n; i++, ii++) {
		for (int j = m / 2; j < m; j++) {
			tmp[ii][j] = arr[i][j];
		}
	}
	for (int i = n / 2; i < n; i++) {
		for (int j = 0, jj = m / 2; j < m / 2; j++, jj++) {
			tmp[i][jj] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = tmp[i][j];
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		int k;
		cin >> k;
		if (k == 1) func1();
		else if (k == 2) func2();
		else if (k == 3) func3();
		else if (k == 4) func4();
		else if (k == 5) func5();
		else func6();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}