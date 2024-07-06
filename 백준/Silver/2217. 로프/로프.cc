#include <bits/stdc++.h> 
using namespace std;

const int INF =  987654321;
const int MOD = 100000000;

/*
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
*/

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int nn = n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	int ans = -INF;
	for (int i = 0; i < nn; i++) {
		ans = max(ans, v[i] * n);
		n--;
	}
	cout << ans;
	return 0;
}