#include <bits/stdc++.h> 
using namespace std;

const int INF = 2e9;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

vector<pair<pair<string, int>, pair<int, int>>> v;

bool cmp(pair<pair<string, int>, pair<int, int>> a, pair<pair<string, int>, pair<int, int>> b) {	
	if (a.first.second == b.first.second) {
		if (a.second.first == b.second.first) {
			if (a.second.second == b.second.second) {
				return a.first.first < b.first.first;
			}
			return a.second.second > b.second.second;
		}
		return a.second.first < b.second.first;
	}
	return a.first.second > b.first.second;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string name;
		int k, e, s;
		cin >> name >> k >> e >> s;
		v.push_back(make_pair(make_pair(name, k), make_pair(e, s)));
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) cout << v[i].first.first << '\n';
	return 0;
}