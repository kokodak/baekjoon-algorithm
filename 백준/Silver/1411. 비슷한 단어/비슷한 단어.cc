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
	vector<string> v;
	int ssize;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
		ssize = s.size();
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int arr[30]; // n번째 알파벳에서 바뀌는 문자 순서
			bool visited[30] = {0,};
			bool flag = true;
			for (int k = 0; k < 30; k++) arr[k] = inf;
			for (int k = 0; k < ssize; k++) {
				if (arr[v[i][k] - 'a'] != inf) {
					if (v[i][k] - arr[v[i][k] - 'a'] != v[j][k]) {
						flag = false;
						break;
					}
				}
				else {
					if (visited[v[j][k] - 'a']) {
						flag = false;
						break;
					}
					arr[v[i][k] - 'a'] = v[i][k] - v[j][k];
					visited[v[j][k] - 'a'] = true;
				}
			}
			if (flag) ans++;
		}
	}
	cout << ans;
	return 0;
}