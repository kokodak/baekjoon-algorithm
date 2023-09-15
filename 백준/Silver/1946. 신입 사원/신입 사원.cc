#include <bits/stdc++.h> 
using namespace std;

const int INF =  987654321;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> v;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}
		sort(v.begin(), v.end(), cmp);
		int tmp = v[0].second;
		int cnt = 1;
		for (int i = 1; i < n; i++) {
			if (tmp > v[i].second) {
				cnt++;
				tmp = v[i].second;
			}
		}
		cout << cnt << '\n';
	}
	
	return 0;
}