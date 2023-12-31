#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;

const int INF = 999999999;
const int MAX = 1000001;
const int MOD = 10007;

/*
ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/

vector<int> tree[MAX];
vector<int> dfsNode[MAX];
bool vi[MAX];
int dp[MAX][2];

void dfs(int node) {
	//단방향 그래프화
	vi[node] = true;

	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];

		if (!vi[next]) {
			dfsNode[node].push_back(next);
			dfs(next);
		}
	}
}

int solve(int node, int isEA) {

	if (dp[node][isEA] != -1) return dp[node][isEA];

	if (isEA) {
		dp[node][isEA] = 1;

		for (int i = 0; i < dfsNode[node].size(); i++) {
			int next = dfsNode[node][i];

			dp[node][isEA] += min(solve(next, 1), solve(next, 0));
		}
	}
	else {
		dp[node][isEA] = 0;

		for (int i = 0; i < dfsNode[node].size(); i++) {
			int next = dfsNode[node][i];

			dp[node][isEA] += solve(next, 1);
		}
	}

	return dp[node][isEA];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	memset(dp, -1, sizeof(dp));

	cout << min(solve(1, 0), solve(1, 1));
	return 0;
}