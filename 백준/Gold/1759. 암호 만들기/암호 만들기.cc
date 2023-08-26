#include <bits/stdc++.h> 
using namespace std;

const int INF = 2e9;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

int l, c;
vector<char> v;
bool visited[15];

void dfs(int cnt, int pos, int m, int j, string tmp) {
	if (cnt == l && m >= 1 && j >= 2) {
		cout << tmp << '\n';
		return;
	}
	for (int i = pos; i < c; i++) {
		char k = v[i];
		if (k == 'a' || k == 'e' || k == 'i' || k == 'o' || k == 'u') {
			tmp.push_back(k);
			dfs(cnt + 1, i + 1, m + 1, j, tmp);
			tmp.pop_back();
		}
		else {
			tmp.push_back(k);
			dfs(cnt + 1, i + 1, m, j + 1, tmp);
			tmp.pop_back();
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		char k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	dfs(0, 0, 0, 0, "");
	return 0;
}