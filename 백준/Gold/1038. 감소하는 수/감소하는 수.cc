#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

int n;
int cnt = 1;
string ans = "";
string anss;

void dfs(int d, int l) {
	if (d == l) {
		if (cnt++ == n) {
			anss = ans;	
		}
		return;
	}
	if (l == 0) {
		for (int i = 1; i <= 9; i++) {
			ans.push_back('0' + i);
			dfs(d, l + 1);
			ans.pop_back();
		}
	}
	else {
		for (int i = 0; i <= 9; i++) {
			if (i >= ans.back() - '0') continue;
			ans.push_back('0' + i);
			dfs(d, l + 1);
			ans.pop_back();
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	if (n > 1022) {
		cout << -1;
		return 0;
	}
	for (int i = 1; ; i++) {
		if (cnt > n) break;
		dfs(i, 0);
	}
	cout << anss;
	return 0;
}