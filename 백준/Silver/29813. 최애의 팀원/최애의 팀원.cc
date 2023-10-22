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

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	queue<pair<string, int>> que;
	for (int i = 0; i < n; i++) {
		string s;
		int num;
		cin >> s >> num;
		que.push({s, num});
	}
	while (que.size() != 1) {
		string s = que.front().X;
		int num = que.front().Y;
		que.pop();
		num %= 100;
		for (int i = 0; i < num - 1; i++) {
			string ns = que.front().X;
			int nnum = que.front().Y;
			que.pop();
			que.push({ns, nnum});
		}
		que.pop();
	}
	cout << que.front().X;
	return 0;
}