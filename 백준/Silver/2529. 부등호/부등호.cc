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

vector<int> v; // <: 0, >: 1
vector<int> num;
vector<ll> ans;
bool visited[10];

bool check(int k) {
	for (int i = 0; i < k; i++) {
		if (v[i] == 0) {
			if (num[i] > num[i + 1]) return false;
		}
		else {
			if (num[i] < num[i + 1]) return false;
		}
	}
	return true;
}

void go(int depth, int k) {
	if (k + 1 == depth) {
		if (check(k)) {
			ll anss = 0;
			for (int i = 0; i < k + 1; i++) {
				anss *= 10;
				anss += num[i];
			}
			ans.push_back(anss);
			// for (int i = 0; i < k + 1; i++) {
			// 	cout << num[i];
			// }
			// cout << endl;
		}
		return;
	}
	
	for (int i = 0; i < 10; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		num.push_back(i);
		go(depth + 1, k);
		num.pop_back();
		visited[i] = false;
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		char c;
		cin >> c;
		if (c == '<') v.push_back(0);
		else v.push_back(1);
	}
	go(0, k);
	sort(ans.begin(), ans.end());
	if (ans[ans.size() - 1] < pow(10, k)) cout << 0;
	cout << ans[ans.size() - 1] << '\n';
	if (ans[0] < pow(10, k)) cout << 0;
	cout << ans[0];
	return 0;
}