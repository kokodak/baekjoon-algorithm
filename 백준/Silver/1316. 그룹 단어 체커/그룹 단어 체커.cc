#include <bits/stdc++.h> 
using namespace std;
const int INF = 2e9;
const int inf = 1e9;

bool visited[26];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// aaa
	int n;
	cin >> n;
	int ans = 0;
	while (n--) {
		string s;
		cin >> s;
		int ssize = s.size();
		memset(visited, 0, sizeof(visited));
		bool ok = true;
		for (int i = 0; i < ssize;) {
			if (i == ssize - 1) {
				if (visited[s[i] - 'a']) ok = false;
				break;
			}
			if (visited[s[i] - 'a']) {
				ok = false;
				break;
			}
			visited[s[i] - 'a'] = true;
			for (int j = i + 1; j < ssize; j++) {
				if (s[j] == s[i]) i++;
				else {
					i++;
					break;
				}
				if (i == ssize - 1) i++;
			}
		}
		if (ok) ans++;
	}
	cout << ans;
	return 0;
}