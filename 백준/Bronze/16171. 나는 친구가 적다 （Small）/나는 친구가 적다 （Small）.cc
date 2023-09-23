#include <bits/stdc++.h> 
using namespace std;

const int INF = 2e9;
const int inf = 1e9;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	string k;
	cin >> k;
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') continue;
		else tmp.push_back(s[i]);
	}
	if (tmp.size() < k.size()) {
		cout << "0";
		return 0;
	}
	else {
		if (tmp == k) {
			cout << "1";
			return 0;
		}
		else {
			for (int i = 0; i < tmp.size() - (k.size() - 1); i++) {
				string ans = "";
				for (int j = i; j < i + k.size(); j++) {
					ans.push_back(tmp[j]);
				}
				if (ans == k) {
					cout << "1";
					return 0;
				}
				else {
					ans.clear();
					continue;
				}
			}
		}
	}
	cout << "0";
	return 0;
}