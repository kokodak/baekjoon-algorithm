#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

const int INF = 987654321;
const int MAX = 32767;
const int MOD = 1000000000;

/*
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

bool vi[9] = { false, };
int arr[9];

void backtrack(int cnt, int n, int m) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!vi[i]) {
			vi[i] = true;
			arr[cnt] = i;
			backtrack(cnt + 1, n, m);
			vi[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m; //1 ~ n까지 m개인 수열 다 출력

	backtrack(0, n, m);
	return 0;
}