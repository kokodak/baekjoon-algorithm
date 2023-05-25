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

vector<int> v;
vector<int> oper; 
int operCnt[4]; // + - * /
int maxx = -inf;
int minn = inf;

int calculate(int n) {
	int ret = v[0];
	for (int i = 1; i < n; i++) {
		if (oper[i - 1] == 0) ret += v[i];
		else if (oper[i - 1] == 1) ret -= v[i];
		else if (oper[i - 1] == 2) ret *= v[i];
		else ret /= v[i];
	}
	return ret;
}

void go(int depth, int n) {
	if (depth == n - 1) {
		int cal = calculate(n);
		maxx = max(maxx, cal);
		minn = min(minn, cal);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (operCnt[i] == 0) continue;
		operCnt[i]--;
		oper.push_back(i);
		go(depth + 1, n);
		oper.pop_back();
		operCnt[i]++;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	for (int i = 0; i < 4; i++) {
		cin >> operCnt[i];
	}
	go(0, n);
	cout << maxx << '\n';
	cout << minn;
	return 0;
}