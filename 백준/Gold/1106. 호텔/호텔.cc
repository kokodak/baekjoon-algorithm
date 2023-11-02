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

struct A {
	int cost;
	int customer;
};

A arr[21];
int dp[1001]; // dp[i] = 고객이 i명 이상 되기 위해 투자해야하는 돈의 최소
int n;

/*
	dp[i] = min(dp[i - arr[k].customer] + arr[k].cost)
*/

int go(int c) { // 고객이 i명일때 돈의 최소
	if (c <= 0) return 0;
	int& ret = dp[c];
	if (ret != -1) return ret;
	ret = inf;
	for (int i = 0; i < n; i++) {
		ret = min(ret, go(c - arr[i].customer) + arr[i].cost);
	}
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	memset(dp, -1, sizeof(dp));
	int c;
	cin >> c >> n;
	for(int i = 0; i < n; i++) {
		cin >> arr[i].cost >> arr[i].customer;
	}
	cout << go(c);
	return 0;
}